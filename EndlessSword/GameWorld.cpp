#include "GameWorld.h"

GameWorld::GameWorld(int Width, int Height) {
	height = Height;
	width = Width;

	// Set window state to closed if the world fails to start
	if (!Start())
		windowClosed = true;
}

GameWorld::~GameWorld() {
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	SDL_Quit();
}

bool GameWorld::Start() {
	// Create the game window
	gameWindow = SDL_CreateWindow("Endless Sword", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	if (gameWindow == nullptr) {
		std::cerr << "Window couldn't be created \n";
		return false;
	}

	// Create the renderer
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
	
	if (gameWindow == nullptr) {
		std::cerr << "Renderer couldn't be created \n";
		return false;
	}

	return true;
}

void GameWorld::HandleEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT: // Close the window
			windowClosed = true;
			break;

		default:
			break;
		}
	}
}

void GameWorld::ClearRenderer(){
	SDL_SetRenderDrawColor(gameRenderer, 204, 229, 255, 255);
	SDL_RenderClear(gameRenderer);
	SDL_RenderPresent(gameRenderer);
}