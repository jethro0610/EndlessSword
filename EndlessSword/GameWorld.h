#pragma once

#include <SDL.h>
#include <iostream>
#include "GameObject.h"
#include "GameObjectList.h"
#include "Vector2D.h"

class GameWorld {
public:
	GameWorld();
	GameWorld(int Width, int Height);
	~GameWorld();

	SDL_Renderer* GetRenderer() { return gameRenderer; };

	void HandleEvents();
	void Draw();
	void AddGameObject(GameObject* ObjectToAdd);
	void DeleteGameObject(GameObject* ObjectToDelete);
	void Update();

	int GetWidth() { return width; };
	int GetHeight() { return height; };

	Vector2D GetMousePosition() { return mousePosition; };

	GameObject* GetFirstObject() { return gameObjects.GetFirstObject(); };
	GameObject* GetLastObject() { return gameObjects.GetLastObject(); };

	static GameWorld* GetWorld();

	bool WindowIsClosed() const{ return windowClosed; }

public:
	int score = 0;

private:
	Vector2D mousePosition;
	bool Start();
	static GameWorld* mainWorld;

private:
	int width = 1000;
	int height = 1000;

	bool windowClosed = false;

	SDL_Window* gameWindow = nullptr;
	SDL_Renderer* gameRenderer = nullptr;

	GameObjectList gameObjects = GameObjectList();
};

