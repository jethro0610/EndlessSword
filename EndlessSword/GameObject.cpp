#include "GameObject.h"
#include "GameWorld.h"
#include <iostream>

GameObject::GameObject() {
	GameWorld::GetWorld()->AddGameObject(this);
}

GameObject::~GameObject() {
}

void GameObject::Update() {

}

void GameObject::Delete() {
	GameWorld::GetWorld()->DeleteGameObject(this);
}