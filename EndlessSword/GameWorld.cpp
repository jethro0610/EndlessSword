#include "GameWorld.h"

GameWorld::GameWorld(int Width, int Height) {
	height = Height;
	width = Width;

	// Set window state to closed if the world fails to start
	if (!Start())
		windowClosed = true;
}

bool GameWorld::Start() {
	// Create the game window
	gameWindow = SDL_CreateWindow("Endless Sword", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	if (gameWindow == nullptr) {
		std::cerr << "Window couldn't be created \n";
		return false;
	}

	return true;
}

GameWorld::~GameWorld() {

}
