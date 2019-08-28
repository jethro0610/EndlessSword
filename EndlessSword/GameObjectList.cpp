#include "GameObjectList.h"
#include <iostream>

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
	while (head != nullptr) {
		currentObject->Update();
		if (currentObject != tail) {
			currentObject = currentObject->nextObjectInList;
		}
		else {
			break; // Stop loop if at the last object
		}
	}
}

void GameObjectList::DeleteObject(GameObject* ObjectToDelete) {
	if (ObjectToDelete != tail) { // Set the previous object of the next object if the object is not the tail
		ObjectToDelete->nextObjectInList->previousObjectInList = ObjectToDelete->previousObjectInList;
	}
	else {
		tail = ObjectToDelete->previousObjectInList; // Set the tail to the previous if this object was the tail
	}

	if (ObjectToDelete != head) { // Set the next object of the previous object if the object is not the head
		ObjectToDelete->previousObjectInList->nextObjectInList = ObjectToDelete->nextObjectInList;
	}
	else {
		// Set the head and tail to null if the deleted object is the head
		head = nullptr;
		tail = nullptr;
	}

	delete ObjectToDelete; // Remove the object from memory
}
