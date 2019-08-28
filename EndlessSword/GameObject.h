#pragma once

// Forward declaration of game world
class GameWorld;

class GameObject {
public:
	GameObject(GameWorld* ObjectGameWorld);
	~GameObject();

	bool IsUpdating() { return shouldUpdate; }

private:
	bool shouldUpdate = true;
	GameWorld* gameWorld;

public:
	virtual void Update();
};

