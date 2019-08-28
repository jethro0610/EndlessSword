#pragma once

// Forward declaration of game world
class GameWorld;

class GameObject {
public:
	GameObject();
	~GameObject();

	bool IsUpdating() { return shouldUpdate; }

protected:
	bool shouldUpdate = true;

private:
	GameObject* previousObjectInList = nullptr;
	GameObject* nextObjectInList = nullptr;

	friend class GameObjectList; // Allow GameObjectList to access private members

public:
	virtual void Update();
	void Delete();
};

