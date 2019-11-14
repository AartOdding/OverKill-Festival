#include <thread>
#include <mutex>
#include <list>
#include <memory>
#include <atomic

#include "ofImage.h"
#include "Character.h"


class ImageLoader
{
public:

    ImageLoader() = default;

    ImageLoader(const ImageLoader&) = delete;

    ImageLoader(ImageLoader&&) = delete;


    void initialize();


    void load_background(const std::string& url);

    void load_character(const std::string& directory);


    bool has_background_ready();

    bool has_character_ready();


    std::unique_ptr<ofImage>&& get_background();

    std::unique_ptr<Character>&& get_character();

private:

    std::atomic<bool> stop_thread = false;

    std::thread worker_thread;

    std::mutex input_mutex;
    std::mutex output_mutex;

    std::list<std::unique_ptr<ofImage>> background_output_queue;
    std::list<std::unique_ptr<Character>> character_output_queue;

    std::vector<std::string> background_input_queue;
    std::vector<std::string> character_input_queue;


    void threaded_function();

}




