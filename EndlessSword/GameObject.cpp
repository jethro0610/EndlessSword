#include "GameObject.h"
#include "GameWorld.h"
#include <iostream>

GameObject::GameObject() {
	// Add the object to the world upon creation
	GameWorld::GetWorld()->AddGameObject(this);
}

GameObject::~GameObject() {
}

void GameObject::Update() {

}

void GameObject::Draw() {

}

void GameObject::Delete() {
	GameWorld::GetWorld()->DeleteGameObject(this);
}