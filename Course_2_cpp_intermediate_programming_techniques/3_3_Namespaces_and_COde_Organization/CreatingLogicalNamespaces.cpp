/*
Refactor the problematic code by organizing functions into appropriate namespaces based on their functionality.

🔍 Practice
Run the refactored code provided and observe the improvements:

    How much clearer is it now what each function does?

    Notice how nested namespaces provide even more organization

    Try adding your own functions to the appropriate namespaces

Add these functions to test your understanding:

    A Graphics::setResolution(int width, int height) function

    A Physics::setGravity(float gravity) function

    An Audio::Effects::playJump() function
*/

#include <iostream>
#include <string>
#include <vector>
// Organized code using namespaces
namespace Graphics {
    void render() {
        std::cout << "Rendering 2D sprites" << std::endl;
    }    
    void render(bool use3D) {
        if (use3D) {
            std::cout << "Rendering 3D models" << std::endl;
        } else {
            std::cout << "Rendering 2D sprites" << std::endl;
        }
    }    
    void initialize() {
        std::cout << "Initializing graphics system" << std::endl;
    }    
    // Nested namespace for advanced rendering features
    namespace Advanced {
        void renderShadows() {
            std::cout << "Rendering advanced shadows" << std::endl;
        }        
        void renderParticles(int particleCount) {
            std::cout << "Rendering " << particleCount << " particles" << std::endl;
        }
    }
}
namespace Audio {
    void play() {
        std::cout << "Playing background music" << std::endl;
    }    
    void play(const std::string& soundEffect) {
        std::cout << "Playing sound effect: " << soundEffect << std::endl;
    }    
    void setVolume(float volume) {
        std::cout << "Setting audio volume to: " << volume << std::endl;
    }    
    // Nested namespace for different audio types
    namespace Music {
        void playTrack(const std::string& filename) {
            std::cout << "Playing music track: " << filename << std::endl;
        }        
        void fadeOut(float duration) {
            std::cout << "Fading out music over " << duration << " seconds" << std::endl;
        }
    }    
    namespace Effects {
        void playExplosion() {
            std::cout << "Playing explosion sound effect" << std::endl;
        }        
        void playFootstep(const std::string& surface) {
            std::cout << "Playing footstep on " << surface << std::endl;
        }
    }
}
namespace Physics {
    void update() {
        std::cout << "Updating physics calculations" << std::endl;
    }    
    void update(double deltaTime) {
        std::cout << "Updating physics with delta time: " << deltaTime << "ms" << std::endl;
    }    
    void initialize(int maxEntities) {
        std::cout << "Initializing physics system with " << maxEntities << " entities" << std::endl;
    }    
    void applyGravity(float force) {
        std::cout << "Applying gravity force: " << force << std::endl;
    }    
    // Nested namespace for collision detection
    namespace Collision {
        bool checkCollision(int entityA, int entityB) {
            std::cout << "Checking collision between entity " << entityA 
                      << " and entity " << entityB << std::endl;
            return true; // Simplified for demonstration
        }        
        void resolveCollision(int entityA, int entityB) {
            std::cout << "Resolving collision between entity " << entityA 
                      << " and entity " << entityB << std::endl;
        }
    }
}
int main() {
    std::cout << "=== Game Engine Initialization ===" << std::endl;    
    // Now it's clear what each function does!
    Graphics::initialize();
    Physics::initialize(1000);    
    std::cout << "\n=== Game Loop ===" << std::endl;
    Graphics::render();
    Graphics::render(true);    
    Physics::update();
    Physics::update(16.67);
    Physics::applyGravity(9.8f);   
    Audio::play();
    Audio::play("explosion.wav");
    Audio::setVolume(0.8f);    
    std::cout << "\n=== Advanced Features ===" << std::endl;
    Graphics::Advanced::renderShadows();
    Graphics::Advanced::renderParticles(500);    
    Audio::Music::playTrack("background.mp3");
    Audio::Effects::playExplosion();
    Audio::Effects::playFootstep("grass");    
    Physics::Collision::checkCollision(1, 2);
    Physics::Collision::resolveCollision(1, 2);    
    return 0;
}

/*
✅ Success Checklist
All functions are organized into logical namespaces

Nested namespaces are used appropriately for advanced features

The code is much more readable and maintainable

You can easily add new functions to the correct namespaces
*/