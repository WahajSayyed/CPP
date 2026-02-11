/*Design an extensible media system that supports new media types without modifying existing code. 
Implement the Open/Closed Principle using polymorphism.

🔍 Practice
Test the extensibility of your polymorphic system using the code below:
    Create StreamingMedia and PodcastEpisode objects
    Add them to existing MediaPlayerEngine playlists
    Verify that all existing functionality works without modification
    Test new media-specific features through RTTI

Demonstrate the Open/Closed Principle:
    Add new media types without changing MediaFile or MediaPlayerEngine
    Show how polymorphism enables seamless integration
    Use the factory function to create different media types dynamically*/

#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include <string>
using namespace std;
// Base class with virtual functions for polymorphism
class MediaFile {
protected:
    string filename;
    double duration;    // in seconds
    long fileSize;      // in bytes    
public:
    MediaFile(const string& name, double dur, long size) 
        : filename(name), duration(dur), fileSize(size) {
        cout << "MediaFile created: " << filename << endl;
    }    
    // Virtual destructor - essential for inheritance
    virtual ~MediaFile() {
        cout << "MediaFile destroyed: " << filename << endl;
    }    
    // Pure virtual functions - make class abstract
    virtual void play() const = 0;
    virtual void pause() const = 0;
    virtual void stop() const = 0;
    virtual string getMediaType() const = 0;    
    // Virtual function with default implementation
    virtual void displayInfo() const {
        cout << "File: " << filename << endl;
        cout << "Duration: " << duration << "s" << endl; 
        cout << "Size: " << fileSize << " bytes" << endl;
        cout << "Type: " << getMediaType() << endl;
    }    
    // Non-virtual utility methods
    string getFilename() const { return filename; }
    double getDuration() const { return duration; }
    long getFileSize() const { return fileSize; }
};
// Audio file implementation
class AudioFile : public MediaFile {
private:
    int bitRate;
    string audioFormat;    
public:
    AudioFile(const string& name, double dur, long size, int rate, const string& format) 
        : MediaFile(name, dur, size), bitRate(rate), audioFormat(format) {
        cout << "AudioFile created: " << audioFormat << " format" << endl;
    }    
    ~AudioFile() {
        cout << "AudioFile destroyed: " << filename << endl;
    }    
    void play() const override {
        cout << "🎵 Playing audio: " << filename << " (" << audioFormat << ")" << endl;
        cout << "Bitrate: " << bitRate << " kbps" << endl;
    }    
    void pause() const override {
        cout << "⏸️ Audio paused: " << filename << endl;
    }    
    void stop() const override {
        cout << "⏹️ Audio stopped: " << filename << endl;
    }    
    string getMediaType() const override {
        return "Audio (" + audioFormat + ")";
    }    
    // Audio-specific method
    void adjustVolume(int volume) const {
        cout << "🔊 Volume set to " << volume << "% for " << filename << endl;
    }    
    int getBitRate() const { return bitRate; }
    string getAudioFormat() const { return audioFormat; }
};
// Video file implementation
class VideoFile : public MediaFile {
private:
    string resolution;
    int frameRate;
    string videoCodec;    
public:
    VideoFile(const string& name, double dur, long size, const string& res, int fps, const string& codec) 
        : MediaFile(name, dur, size), resolution(res), frameRate(fps), videoCodec(codec) {
        cout << "VideoFile created: " << resolution << " @ " << frameRate << "fps" << endl;
    }    
    ~VideoFile() {
        cout << "VideoFile destroyed: " << filename << endl;
    }    
    void play() const override {
        cout << "🎬 Playing video: " << filename << endl;
        cout << "Resolution: " << resolution << " @ " << frameRate << "fps" << endl;
        cout << "Codec: " << videoCodec << endl;
    }    
    void pause() const override {
        cout << "⏸️ Video paused: " << filename << endl;
    }    
    void stop() const override {
        cout << "⏹️ Video stopped: " << filename << endl;
    }    
    string getMediaType() const override {
        return "Video (" + videoCodec + ")";
    }    
    // Video-specific method
    void changeQuality(const string& newRes) const {
        cout << "📺 Quality changed to " << newRes << " for " << filename << endl;
    }    
    string getResolution() const { return resolution; }
    int getFrameRate() const { return frameRate; }
    string getVideoCodec() const { return videoCodec; }
};

// New media type - demonstrates extensibility
class StreamingMedia : public MediaFile {
private:
    string streamURL;
    int bandwidth;      // in Mbps
    bool isLive;    
public:
    StreamingMedia(const string& name, const string& url, int bw, bool live) 
        : MediaFile(name, live ? 0 : 3600, 0), // Live streams have unknown duration
          streamURL(url), bandwidth(bw), isLive(live) {
        cout << "StreamingMedia created: " << (live ? "Live" : "On-demand") << " stream" << endl;
    }    
    ~StreamingMedia() {
        cout << "StreamingMedia destroyed: " << filename << endl;
    }    
    void play() const override {
        cout << "📡 Streaming: " << filename << endl;
        cout << "URL: " << streamURL << endl;
        cout << "Bandwidth: " << bandwidth << " Mbps" << endl;
        cout << "Mode: " << (isLive ? "Live broadcast" : "On-demand") << endl;
    }    
    void pause() const override {
        if (isLive) {
            cout << "⚠️ Cannot pause live stream: " << filename << endl;
        } else {
            cout << "⏸️ Stream paused: " << filename << endl;
        }
    }    
    void stop() const override {
        cout << "🔌 Stream stopped: " << filename << endl;
    }    
    string getMediaType() const override {
        return isLive ? "Live Stream" : "Streaming Media";
    }    
    void displayInfo() const override {
        MediaFile::displayInfo();  // Call base implementation
        cout << "Stream URL: " << streamURL << endl;
        cout << "Bandwidth: " << bandwidth << " Mbps" << endl;
        cout << "Type: " << (isLive ? "Live" : "On-demand") << endl;
    }    
    // Streaming-specific methods
    void changeQuality(int newBandwidth) const {
        cout << "📊 Stream quality changed to " << newBandwidth << " Mbps" << endl;
    }    
    void bufferContent() const {
        if (!isLive) {
            cout << "📥 Buffering content for smooth playback..." << endl;
        }
    }    
    string getStreamURL() const { return streamURL; }
    int getBandwidth() const { return bandwidth; }
    bool getIsLive() const { return isLive; }
};
// Another extension - Podcast media
class PodcastEpisode : public MediaFile {
private:
    string showName;
    int episodeNumber;
    string description;    
public:
    PodcastEpisode(const string& episode, const string& show, int epNum, 
                   double dur, const string& desc) 
        : MediaFile(episode, dur, 50000000), // ~50MB typical
          showName(show), episodeNumber(epNum), description(desc) {
        cout << "PodcastEpisode created: " << show << " #" << epNum << endl;
    }    
    ~PodcastEpisode() {
        cout << "PodcastEpisode destroyed: " << filename << endl;
    }    
    void play() const override {
        cout << "🎙️ Playing podcast: " << showName << endl;
        cout << "Episode #" << episodeNumber << ": " << filename << endl;
        cout << "Description: " << description << endl;
    }    
    void pause() const override {
        cout << "⏸️ Podcast paused: " << filename << endl;
    }    
    void stop() const override {
        cout << "⏹️ Podcast stopped: " << filename << endl;
    }    
    string getMediaType() const override {
        return "Podcast Episode";
    }    
    void displayInfo() const override {
        MediaFile::displayInfo();
        cout << "Show: " << showName << endl;
        cout << "Episode: #" << episodeNumber << endl;
        cout << "Description: " << description << endl;
    }    
    // Podcast-specific methods
    void skipIntro() const {
        cout << "⏩ Skipping intro for " << filename << endl;
    }    
    void setPlaybackSpeed(double speed) const {
        cout << "🎛️ Playback speed set to " << speed << "x for " << filename << endl;
    }    
    string getShowName() const { return showName; }
    int getEpisodeNumber() const { return episodeNumber; }
};
// Factory function for creating different media types
unique_ptr<MediaFile> createMediaFile(const string& type, const vector<string>& params) {
    if (type == "audio" && params.size() >= 5) {
        return make_unique<AudioFile>(params[0], stod(params[1]), stol(params[2]), 
                                     stoi(params[3]), params[4]);
    }
    else if (type == "video" && params.size() >= 6) {
        return make_unique<VideoFile>(params[0], stod(params[1]), stol(params[2]), 
                                     params[3], stoi(params[4]), params[5]);
    }
    else if (type == "stream" && params.size() >= 4) {
        return make_unique<StreamingMedia>(params[0], params[1], stoi(params[2]), 
                                          params[3] == "true");
    }
    else if (type == "podcast" && params.size() >= 5) {
        return make_unique<PodcastEpisode>(params[0], params[1], stoi(params[2]), 
                                          stod(params[3]), params[4]);
    }    
    return nullptr;
}

int main() {
    cout << "===== Open/Closed Media System Demo =====\n" << endl;

    // Create playlist container (no engine changes needed)
    vector<unique_ptr<MediaFile>> playlist;

    // Create media using factory function (dynamic creation)
    playlist.push_back(createMediaFile("audio",
        {"song.mp3", "210.5", "5000000", "320", "MP3"}));

    playlist.push_back(createMediaFile("video",
        {"movie.mp4", "7200", "2200000000", "1080p", "60", "H.264"}));

    playlist.push_back(createMediaFile("stream",
        {"Live News", "https://live.news.com", "15", "true"}));

    playlist.push_back(createMediaFile("podcast",
        {"AI Revolution", "TechTalks", "42", "3600", "Future of AI systems"}));

    playlist.push_back(createMediaFile("stream",
        {"Music Stream", "https://music.stream.com", "8", "false"}));

    cout << "\n===== Pure Polymorphic Playback =====" << endl;

    // Polymorphism: existing code works for new types
    for (const auto& media : playlist) {
        cout << "\n-----------------------------" << endl;
        media->displayInfo();
        media->play();
        media->pause();
        media->stop();
    }

    cout << "\n===== RTTI-Based Extensions =====" << endl;

    // RTTI enables type-specific behavior without modifying base code
    for (const auto& media : playlist) {

        if (auto* stream = dynamic_cast<StreamingMedia*>(media.get())) {
            cout << "\n🌐 Streaming enhancements detected" << endl;
            stream->changeQuality(12);
            stream->bufferContent();
        }
        else if (auto* podcast = dynamic_cast<PodcastEpisode*>(media.get())) {
            cout << "\n🎧 Podcast enhancements detected" << endl;
            podcast->skipIntro();
            podcast->setPlaybackSpeed(1.25);
        }
        else if (auto* audio = dynamic_cast<AudioFile*>(media.get())) {
            cout << "\n🎵 Audio enhancements detected" << endl;
            audio->adjustVolume(80);
        }
        else if (auto* video = dynamic_cast<VideoFile*>(media.get())) {
            cout << "\n🎬 Video enhancements detected" << endl;
            video->changeQuality("4K");
        }
    }

    cout << "\n===== Open/Closed Principle Verified =====" << endl;
    cout << "✔ New media types added" << endl;
    cout << "✔ No changes to MediaFile or existing logic" << endl;
    cout << "✔ Polymorphism handled integration seamlessly" << endl;

    cout << "\n===== Program End =====" << endl;
    return 0;
}
/*
✅ Success Checklist
New media types integrate without modifying existing classes
Polymorphic behavior works consistently across all media types
RTTI identifies new types correctly in existing functions
System demonstrates professional extensibility patterns

💡 Key Points
Virtual functions enable polymorphism - base class pointers can call derived class methods dynamically
Pure virtual functions create abstract classes - prevent instantiation while defining interface contracts
Dynamic binding resolves method calls at runtime - vtables enable efficient polymorphic dispatch
RTTI provides runtime type identification - dynamic_cast and typeid enable safe type-specific operations
Open/Closed Principle supports extensibility - add new functionality without modifying existing code
Smart pointers manage polymorphic objects safely - automatic cleanup prevents memory leaks

❗ Common Mistakes to Avoid
Forgetting virtual destructors in base classes designed for inheritance
Using dynamic_cast unnecessarily instead of relying on virtual functions
Creating virtual function overhead in performance-critical inner loops
Not making pure virtual functions when base implementation doesn't make sense
Mixing ownership models when using polymorphic containers
Overusing RTTI instead of designing proper virtual interfaces

🚀 Next Steps
Polymorphic design patterns are essential for building enterprise software architectures, game engines, plugin systems, and any application requiring runtime flexibility. Professional developers use these techniques to create maintainable systems that can evolve with changing requirements while preserving existing functionality. Your understanding of virtual functions and dynamic binding prepares you for advanced design patterns like Strategy, Factory, and Observer that form the backbone of scalable software systems.*/