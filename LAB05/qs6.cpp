#include <iostream>
using namespace std;

class GraphicsEngine {
public:
    void render() {
        cout << "Rendering graphics...\n";
    }
};

class InputHandler {
public:
    void processInput() {
        cout << "Processing player input...\n";
    }
};

class PhysicsEngine {
public:
    void updatePhysics() {
        cout << "Updating physics...\n";
    }
};

class GameEngine {
private:
    GraphicsEngine graphics;
    InputHandler input;
    PhysicsEngine physics;

public:
    void run() {
        cout << "Starting Game Engine...\n";
        input.processInput();
        physics.updatePhysics();
        graphics.render();
        cout << "Game Engine Cycle Complete.\n";
    }
};

int main() {
    GameEngine game;
    game.run();
    return 0;
}
