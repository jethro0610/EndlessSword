#include "Spawner.h"
#include "Diamond.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <random>
#include <iostream>
#include "GameWorld.h"

Spawner::Spawner(float Interval) {
	spawnInterval = Interval;
	timer = 0.0f;
}

Spawner::~Spawner() {
}

void Spawner::Update() {
	timer += 1.0f;
	if (timer >= spawnInterval)
		Spawn();
}

void Spawner::Spawn() {
	// Generate random number 0-100
	int randomNumber = rand() % 101;

	// Generate random position
	int randX = rand() % GameWorld::GetWorld()->GetWidth() + 1;
	int randY = rand() % GameWorld::GetWorld()->GetHeight() + 1;

	Vector2D worldCenter = Vector2D(GameWorld::GetWorld()->GetWidth() / 2, GameWorld::GetWorld()->GetHeight() / 2);

	if (Vector2D(randX, randY).GetDistance(worldCenter) > 300.0f) {
		if (randomNumber >= 0 && randomNumber < 50) {
			Diamond* spawnedGeo = new Diamond();
			spawnedGeo->position = Vector2D(randX, randY);
		}
		else if (randomNumber > 50 && randomNumber < 90) {
			Octagon* spawnedGeo = new Octagon();
			spawnedGeo->position = Vector2D(randX, randY);
		}
		else {
			Hexagon* spawnedGeo = new Hexagon();
			spawnedGeo->position = Vector2D(randX, randY);
		}
		timer = 0.0f;
	}
}

