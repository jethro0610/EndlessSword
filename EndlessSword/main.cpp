#include <iostream>
#include <SDL.h>
#include "GameWorld.h"

int main(int argc, char** argv) {
	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL failed \n";
	}
	else {
		std::cout << "SDL initialized";
	}

	GameWorld gameWorld = GameWorld(800, 800);
	while (!gameWorld.WindowIsClosed()) {
		gameWorld.HandleEvents();
	}

	return 0;
}