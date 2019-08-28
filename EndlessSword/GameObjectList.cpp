#include "GameObjectList.h"

GameObjectList::GameObjectList()
{
}


GameObjectList::~GameObjectList()
{
}

void GameObjectList::Add(GameObject* ObjectToAdd) {
	if (head == nullptr) {
		head = ObjectToAdd;
		tail = ObjectToAdd;
	}
	else {
		tail->nextObjectInList = ObjectToAdd;
		ObjectToAdd->previousObjectInList = tail;
		tail = ObjectToAdd;
	}
}

void GameObjectList::UpdateAll() {
	GameObject* currentObject = head;
	// Only start the loop if the head is set
	while (currentObject != nullptr) {
		currentObject->Update();
		if (currentObject != tail) {
			currentObject = currentObject->nextObjectInList;
		}
		else {
			currentObject = nullptr; // Stop loop if at the last object
		}
	}
}

void GameObjectList::DeleteObject(GameObject* ObjectToDelete) {
	ObjectToDelete->previousObjectInList->nextObjectInList = ObjectToDelete->nextObjectInList; // Set the next object of the previous object
	ObjectToDelete->nextObjectInList->previousObjectInList = ObjectToDelete->previousObjectInList; // Set the previous object of the next object
	delete ObjectToDelete; // Remove the object from memory
}
