#include "ofApp.h"





void ofApp::setup()
{
	if (FAILED(GetDefaultKinectSensor(&kinect))) throw std::runtime_error("No kinect device found, install drivers and plug in the kinect.");

	BOOLEAN open_already;
	kinect->get_IsOpen(&open_already);

	if (!open_already) if (FAILED(kinect->Open())) throw std::runtime_error("Kinect failed to open, restart and try again?");

	IBodyFrameSource* skeleton_source = nullptr;
	kinect->get_BodyFrameSource(&skeleton_source);

	if (skeleton_source)
	{
		skeleton_source->OpenReader(&skeleton_reader);
		skeleton_source->Release();
	}

	//std::filesystem::path path{ "C:/Users/aart/Desktop/of_v0.10.1_vs2017_release/apps/myApps/KinectAnimations/bin/data/Roboto-Regular.ttf" };
	std::filesystem::path path{ "C:/Users/aart/Desktop/of_v0.10.1_vs2017_release/apps/myApps/KinectAnimations/bin/data/PermanentMarker-Regular.ttf" };
	ofTrueTypeFontSettings fontSettings{ path, 28 };

	std::cout << "loading font: " << font.load(fontSettings) << std::endl;



	////////////////////////////////////////////////////

	ofImage test{ "https://en.wikipedia.org/wiki/Battle_of_France#/media/File:Battle_of_France_collage.jpg" };

	ofSetFrameRate(60);

	background = std::make_unique<ofImage>("background0.jpg");
	characters.push_back(std::make_unique<Character>("player1"));
	
	web_socket = std::unique_ptr<WebSocket>(WebSocket::from_url("ws://172.20.10.3:8080"));
	//web_socket = std::unique_ptr<WebSocket>(WebSocket::from_url("ws://116.203.98.1:8080"));
	//web_socket = std::unique_ptr<WebSocket>(WebSocket::from_url("ws://192.168.1.100:8080"));

}


void ofApp::exit()
{
	if (web_socket)
	{
		std::cout << "exiting\n";
		web_socket->send("OK BYE!");
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		web_socket->close();
	}
	kinect->Close();
	skeleton_reader->Release();
	kinect->Release();
}


void ofApp::receive(const std::string& message)
{
	std::cout << message << "\n";
	auto parts = ofSplitString(message, " ");

	if (!parts.empty())
	{
		if (parts[0] == "backgroundUrl")
		{
			background = std::make_unique<ofImage>(parts[1]);
		}
		else if (parts[0] == "promptText")
		{
			parts.erase(parts.begin());
			promptText = ofJoinString(parts, " ");
			promptWidth = font.stringWidth(promptText);
			promptHeight = font.stringHeight(promptText);
		}
		else if (parts[0] == "startRecording")
		{
			isRecording = true;
		}
		else if (parts[0] == "stopRecording")
		{
			isRecording = false;
		}
	}
}


void ofApp::update()
{
	IBodyFrame* frame = nullptr;
	auto status = skeleton_reader->AcquireLatestFrame(&frame);

	if (SUCCEEDED(status)) {

		players.clear();

		std::array<IBody*, BODY_COUNT> new_kinect_bodies = { 0, 0, 0, 0, 0, 0 };

		status = frame->GetAndRefreshBodyData(BODY_COUNT, new_kinect_bodies.data());

		if (SUCCEEDED(status)) {

			for (auto body : new_kinect_bodies)
			{
				BOOLEAN is_tracked;
				body->get_IsTracked(&is_tracked);

				if (is_tracked)
				{
					players.push_back(std::make_unique<Player>(body));
				}
			}

			for (auto body : new_kinect_bodies)
			{
				body->Release();
			}
			frame->Release();
		}
	}

	if (web_socket)
	{
		web_socket->poll(0);
		web_socket->dispatch([=](const std::string& msg) { this->receive(msg); });
	}
}



void ofApp::draw()
{
	background->draw(0, 0, ofGetWidth(), ofGetHeight());

	for (auto& p : players)
	{
		p->draw(*characters[0]);
	}

	auto x = (ofGetWidth() - promptWidth) / 2;
	auto y = ofGetHeight() - promptHeight - 20;

	ofSetColor(0, 70);
	ofDrawRectangle(x - 30, y - promptHeight - 30, promptWidth + 60, promptHeight + 60);
	ofSetColor(255);

	font.drawString(promptText, x, y);

	//ofDrawBitmapString(promptText, ofGetWidth() / 2, ofGetHeight() - 60);

	if (isRecording)
	{
		//img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		//img.save("screenshot.png");

		ofSetColor(255, 0, 0);
		ofDrawCircle(ofGetWidth() - 50, 50, 30);
		ofSetColor(255, 255, 255);
	}

	if (isDebug)
	{
		ofDrawBitmapString(ofGetFrameRate(), 30, 30);
	}

	// draw players with right characters

}



void ofApp::keyReleased(int key)
{
	if (key == 'f')
	{
		ofToggleFullscreen();
	}
	else if (key == 'd')
	{
		isDebug = !isDebug;
	}
	else if (key >= '0' && key <= '9')
	{
		std::string name = "background" + std::to_string(key - '0') + ".jpg";
		std::cout << "Loading new background: " << name << "\n";
		background = std::make_unique<ofImage>(name);
	}
}
