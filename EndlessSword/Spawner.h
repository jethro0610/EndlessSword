#pragma once
#include "GameObject.h"
class Spawner :
	public GameObject
{
public:
	Spawner(float Interval);
	~Spawner();

	void Update() override;

private:
	void Spawn();

private:
	float spawnInterval;
	float timer;
};

