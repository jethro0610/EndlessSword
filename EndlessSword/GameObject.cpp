#include "GameObject.h"
#include "GameWorld.h"
#include <iostream>

GameObject::GameObject(GameWorld* ObjectGameWorld) {
	gameWorld = ObjectGameWorld;
	gameWorld->AddGameObject(this);
}

GameObject::~GameObject() {
}

void GameObject::Update() {

}

void GameObject::Delete() {
	gameWorld->DeleteGameObject(this);
}