#pragma once

#include <SDL.h>
#include <iostream>

class GameWorld {
public:
	GameWorld(int Width, int Height);
	~GameWorld();

	inline bool WindowIsClosed() const{ return windowClosed; }

private:
	bool Start();

private:
	int width = 1000;
	int height = 1000;

	bool windowClosed = false;

	SDL_Window* gameWindow = nullptr;
	SDL_Renderer* gameRenderer = nullptr;
};

