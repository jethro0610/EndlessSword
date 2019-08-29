#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "GameWorld.h"
#include "GeoHole.h"
#include "Spawner.h"

int main(int argc, char** argv) {
	int spawnInterval;
	std::cout << "What should the spawn interval be? (Minimum: 50) ";
	std::cin >> spawnInterval;

	if (spawnInterval < 50)
		spawnInterval = 50;
	std::cout << "Set spawn interval to " << spawnInterval << std::endl;

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
	Spawner* spawner = new Spawner(spawnInterval);

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