#pragma once

#include <vector>
#include <string>
#include <memory>

#include "ofMain.h"

#include "Kinect.h"
#include "easywsclient.hpp"

#include "Player.h"
#include "Character.h"

using easywsclient::WebSocket;



class ofApp : public ofBaseApp
{

public:

	void setup();
	void exit();

	void update();
	void draw();

	void keyReleased(int key);

	void receive(const std::string& message);

private:

	IKinectSensor* kinect = nullptr;
	IBodyFrameReader* skeleton_reader = nullptr;

	std::unique_ptr<ofImage> background;
	std::unique_ptr<WebSocket> web_socket;

	ofImage img;

	ofTrueTypeFont font;

	std::string promptText = "";
	int promptWidth = 0;
	int promptHeight = 0;

	bool isRecording = false;
	bool isDebug = false;

	std::vector<std::unique_ptr<Player>> players;
	std::vector<std::unique_ptr<Character>> characters;

};
