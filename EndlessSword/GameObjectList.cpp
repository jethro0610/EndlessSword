#include "GameObjectList.h"
#include <iostream>

GameObjectList::GameObjectList()
{
}


GameObjectList::~GameObjectList()
{
}

void GameObjectList::Add(GameObject* ObjectToAdd) {
	if (head == nullptr) { // Set the head and tail to the added object if it is the only one in the list
		head = ObjectToAdd;
		tail = ObjectToAdd;
	}
	else { // Add any new objects to the end of the list
		tail->nextObjectInList = ObjectToAdd;
		ObjectToAdd->previousObjectInList = tail;
		tail = ObjectToAdd;
	}
}

void GameObjectList::UpdateAll() {
	GameObject* currentObject = head;
	while (head != nullptr) { // Only start the loop if the head is set
		GameObject* nextObject = currentObject->nextObjectInList; // Have to set next before update because object can be deleted during update
		currentObject->Update();

		if (currentObject != tail && nextObject != nullptr) {
			currentObject = nextObject;
		}
		else {
			break; // Stop loop if at the last object
		}
	}
}

void GameObjectList::DrawAll() {
	GameObject* currentObject = head;
	while (head != nullptr) { // Only start the loop if the head is set
		GameObject* nextObject = currentObject->nextObjectInList; // Have to set next before draw because object can be deleted during draw
		currentObject->Draw();

		if (currentObject != tail && nextObject != nullptr) {
			currentObject = nextObject;
		}
		else {
			break; // Stop loop if at the last object
		}
	}
}

void GameObjectList::DeleteObject(GameObject* ObjectToDelete) {

	// Change the head if the head is deleted
	if (ObjectToDelete == head && ObjectToDelete != tail)
		head = ObjectToDelete->nextObjectInList;

	// Null the head and tail if the object is the only one in the list
	if (ObjectToDelete == head && ObjectToDelete == tail) {
		head = nullptr;
		tail = nullptr;
	}
	
	// Set the next of the previous object
	if (ObjectToDelete->nextObjectInList != nullptr)
		ObjectToDelete->nextObjectInList->previousObjectInList = ObjectToDelete->previousObjectInList;

	// Set the previous of the next object
	if(ObjectToDelete->previousObjectInList != nullptr)
		ObjectToDelete->previousObjectInList->nextObjectInList = ObjectToDelete->nextObjectInList;
	
	delete ObjectToDelete; // Remove the object from memory
}
