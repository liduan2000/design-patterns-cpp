#include <iostream>
#include <string>

// subsystem
class AudioPlayer {
  public:
    void playAudio(const std::string& audio) const { std::cout << "Playing audio: " << audio << std::endl; }

    void stopAudio() const { std::cout << "Stopping audio" << std::endl; }
};

// subsystem
class VideoPlayer {
  public:
    void playVideo(const std::string& video) const { std::cout << "Playing video: " << video << std::endl; }

    void stopVideo() const { std::cout << "Stopping video" << std::endl; }
};

// subsystem
class LightController {
  public:
    void dimLights() const { std::cout << "Dimming lights" << std::endl; }

    void brightenLights() const { std::cout << "Brightening lights" << std::endl; }
};

// facade
class MultimediaFacade {
  public:
    void startMovie(const std::string& audio, const std::string& video) const {
        std::cout << "Starting movie..." << std::endl;
        lightController_.dimLights();
        videoPlayer_.playVideo(video);
        audioPlayer_.playAudio(audio);
    }

    void stopMovie() const {
        std::cout << "Stopping movie..." << std::endl;
        audioPlayer_.stopAudio();
        videoPlayer_.stopVideo();
        lightController_.brightenLights();
    }

  private:
    AudioPlayer audioPlayer_;
    VideoPlayer videoPlayer_;
    LightController lightController_;
};

int main() {
    MultimediaFacade multimediaFacade;
    multimediaFacade.startMovie("Background Music", "Iron Man");
    multimediaFacade.stopMovie();

    return 0;
}