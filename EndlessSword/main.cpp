#include <iostream>
#include <SDL.h>
#include "GameWorld.h"
#include "Geo.h"
#include "GeoHole.h"
#include "Diamond.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Spawner.h"
#include "TransformObject.h"

int main(int argc, char** argv) {
	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL failed" << std::endl;
	}
	else {
		std::cout << "SDL initialized" << std::endl;
	}

	IMG_Init(IMG_INIT_PNG);
	
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