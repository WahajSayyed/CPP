/*
You're working on a game engine where multiple developers have contributed code without proper organization. Start by examining the current problematic codebase.

🔍 Practice
Run the code provided and observe the output. Think about:

How difficult is it to understand what each function does?

What happens if two developers create functions with the same name?

How would you organize these functions into logical groups?

Look at the function names and their behaviors:

Which functions seem to belong to graphics/rendering?

Which functions handle audio/sound?

Which functions manage physics?

💻 Code */
#include <iostream>
#include <string>
#include <vector>
// Global functions from different developers - naming conflicts ahead!
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
void play() {
    std::cout << "Playing background music" << std::endl;
}
void play(std::string soundEffect) {
    std::cout << "Playing sound effect: " << soundEffect << std::endl;
}
void update() {
    std::cout << "Updating physics calculations" << std::endl;
}
void update(double deltaTime) {
    std::cout << "Updating physics with delta time: " << deltaTime << std::endl;
}
void initialize() {
    std::cout << "Initializing graphics system" << std::endl;
}
void initialize(int maxEntities) {
    std::cout << "Initializing physics system with " << maxEntities << " entities" << std::endl;
}
int main() {
    // This code is confusing - which functions do what?
    render();
    render(true);
    play();
    play("explosion.wav");
    update();
    update(16.67);
    initialize();
    initialize(1000);    
    return 0;
}

/*
✅ Success Checklist
The code compiles and runs successfully

You can identify at least three logical groups of functionality

You understand why the current organization is problematic  
*/