#pragma once
#include "GameObject.h"

// Linked list of game objects
class GameObjectList
{
public:
	GameObjectList();
	~GameObjectList();

	void Add(GameObject* ObjectToAdd);
	void UpdateAll();
	void DeleteObject(GameObject* ObjectToDelete);

private:
	GameObject* head = nullptr;
	GameObject* tail = nullptr;
};

