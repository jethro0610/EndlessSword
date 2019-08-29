#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "GameWorld.h"
#include "GeoHole.h"
#include "Spawner.h"

int main(int argc, char** argv) {
	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL failed" << std::endl;
	}
	else {
		std::cout << "SDL initialized" << std::endl;
	}

	// Init image
	IMG_Init(IMG_INIT_PNG);
	// Init text
	TTF_Init();

	GameWorld gameWorld = GameWorld(800, 800);
	Spawner* spawner = new Spawner(100);

	GeoHole* hole = new GeoHole();
	hole->position = Vector2D(400, 400);

	// Run the game
	while (!gameWorld.WindowIsClosed()) {
		gameWorld.HandleEvents();
		gameWorld.Update();
		gameWorld.Draw();
	}

	return 0;
}