#include "ImageLoader.h"



void ImageLoader::initialize()
{

}


void ImageLoader::load_background(const std::string& url)
{
    std::lock_guard<std::mutex> lock{ input_mutex };
    background_input_queue.push_back(url);
}

void ImageLoader::load_character(const std::string& directory)
{
    std::lock_guard<std::mutex> lock{ input_mutex };
    character_input_queue.push_back(directory);
}


bool ImageLoader::has_background_ready()
{
    std::lock_guard<std::mutex> lock{ output_mutex };
    return !background_output_queue.empty();
}

bool ImageLoader::has_character_ready()
{
    std::lock_guard<std::mutex> lock{ output_mutex };
    return !background_output_queue.empty();
}


std::unique_ptr<ofImage>&& ImageLoader::get_background()
{
    std::lock_guard<std::mutex> lock{ output_mutex };

    if (!background_output_queue.empty();)
    {
        return std::unique_ptr<ofImage>();
    }
    else
    {
        auto temp = std::move(background_output_queue.front()):
        background_output_queue.pop_front();
        return std::move(temp);
    }
}

std::unique_ptr<Character>&& ImageLoader::get_character()
{
    std::lock_guard<std::mutex> lock{ output_mutex };
    
    if (!character_output_queue.empty();)
    {
        return std::unique_ptr<Character>();
    }
    else
    {
        auto temp = std::move(character_output_queue.front()):
        background_output_queue.pop_front();
        return std::move(temp);
    }
}
