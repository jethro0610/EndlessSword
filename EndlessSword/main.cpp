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

	// Always handle events and clear the renderer
	while (!gameWorld.WindowIsClosed()) {
		gameWorld.HandleEvents();
		gameWorld.Draw();
		gameWorld.Update();
	}

	return 0;
}