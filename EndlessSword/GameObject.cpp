#include "GameObject.h"
#include "GameWorld.h"

GameObject::GameObject(GameWorld* ObjectGameWorld) {
	gameWorld = ObjectGameWorld;
	gameWorld->AddGameObject(this);
}

GameObject::~GameObject() {
}

void GameObject::Update() {

}