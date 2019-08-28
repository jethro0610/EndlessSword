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
	GameObject* previousObjectInList = nullptr;
	GameObject* nextObjectInList = nullptr;

	friend class GameObjectList; // Allow GameObjectList to access private members

public:
	virtual void Update();
};

