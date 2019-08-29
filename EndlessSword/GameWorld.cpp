#include "GameWorld.h"
#include <iostream>
#include <string>

// Define at start for static
GameWorld* GameWorld::mainWorld;

GameWorld::GameWorld() {
	// Set window state to closed if the world fails to start
	if (!Start())
		windowClosed = true;
}

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
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (gameWindow == nullptr) {
		std::cerr << "Renderer couldn't be created \n";
		return false;
	}

	font = TTF_OpenFont("Sans.ttf", 24);
	if (font == nullptr)
		std::cout << "f" << std::endl;

	uiRect.x = 0;
	uiRect.y = 0;
	uiRect.w = 100;
	uiRect.h = 100;

	AddScore(0);

	GameWorld::mainWorld = this;
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

void GameWorld::Draw(){
	// Clear renderer before drawing
	// Not doing so would cause trailing
	SDL_SetRenderDrawColor(gameRenderer, 255, 255, 255, 255);
	SDL_RenderClear(gameRenderer);

	gameObjects.DrawAll();

	SDL_RenderCopy(gameRenderer, texture, nullptr, &uiRect);

	SDL_RenderPresent(gameRenderer);
}

void GameWorld::AddGameObject(GameObject* ObjectToAdd) {
	gameObjects.Add(ObjectToAdd);
}

void GameWorld::DeleteGameObject(GameObject* ObjectToDelete) {
	gameObjects.DeleteObject(ObjectToDelete);
}

void GameWorld::Update() {
	// Update mouse position
	int mouseX;
	int mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	mousePosition = Vector2D(mouseX, mouseY);

	gameObjects.UpdateAll();
}

GameWorld* GameWorld::GetWorld() {
	return mainWorld;
}

void GameWorld::AddScore(int PointsToAdd) {
	score += PointsToAdd;

	surface = TTF_RenderText_Solid(font, ("Score: " + std::to_string(score)).c_str(), color);
	texture = SDL_CreateTextureFromSurface(gameRenderer, surface);
	SDL_FreeSurface(surface);
}