#pragma once

#include <SDL.h>
#include <iostream>
#include "GameObject.h"
#include "GameObjectList.h"

class GameWorld {
public:
	GameWorld();
	GameWorld(int Width, int Height);
	~GameWorld();

	void HandleEvents();
	void Draw();
	void AddGameObject(GameObject* ObjectToAdd);
	void DeleteGameObject(GameObject* ObjectToDelete);
	void Update();

	bool WindowIsClosed() const{ return windowClosed; }

private:
	bool Start();

private:
	int width = 1000;
	int height = 1000;

	bool windowClosed = false;

	SDL_Window* gameWindow = nullptr;
	SDL_Renderer* gameRenderer = nullptr;

	GameObjectList gameObjects = GameObjectList();
};

