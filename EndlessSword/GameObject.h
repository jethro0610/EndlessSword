#pragma once

#include "GameWorld.h"

class GameObject {
public:
	GameObject(GameWorld ObjectGameWorld);
	~GameObject();

	bool IsUpdating() { return shouldUpdate; }

private:
	bool shouldUpdate = true;
	GameWorld gameWorld;

protected:
	virtual void Update();
};

