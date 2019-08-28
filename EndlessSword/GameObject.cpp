#include "GameObject.h"
#include "GameWorld.h"

GameObject::GameObject(GameWorld* ObjectGameWorld) {
	gameWorld = ObjectGameWorld;
}

GameObject::~GameObject() {
}

void GameObject::Update() {

}