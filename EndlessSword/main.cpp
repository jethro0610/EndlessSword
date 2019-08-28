#include <iostream>
#include <SDL.h>
#include "GameWorld.h"

int main(int argc, char** argv) {
	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL failed" << std::endl;
	}
	else {
		std::cout << "SDL initialized" << std::endl;
	}

	GameWorld gameWorld = GameWorld(800, 800);

	// Run the game
	while (!gameWorld.WindowIsClosed()) {
		gameWorld.HandleEvents();
		gameWorld.Update();
		gameWorld.Draw();
	}

	return 0;
}