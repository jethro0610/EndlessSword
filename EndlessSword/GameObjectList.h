#pragma once
#include "GameObject.h"
#include <vector>

// Linked list of game objects
class GameObjectList
{
public:
	GameObjectList();
	~GameObjectList();

	void Add(GameObject* ObjectToAdd);
	void UpdateAll();
	void DrawAll();
	void DeleteObject(GameObject* ObjectToDelete);

	GameObject* GetFirstObject() { return head; };
	GameObject* GetLastObject() { return tail; };

private:
	GameObject* head = nullptr;
	GameObject* tail = nullptr;
};

