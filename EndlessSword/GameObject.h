#pragma once

// Forward declaration of game world
class GameWorld;

class GameObject {
public:
	GameObject();
	~GameObject();

	bool IsUpdating() { return shouldUpdate; }

	GameObject* GetPrevious() { return previousObjectInList; };
	GameObject* GetNext() { return nextObjectInList; };

protected:
	bool shouldUpdate = true;

private:
	GameObject* previousObjectInList = nullptr;
	GameObject* nextObjectInList = nullptr;

	bool queueForDeletion = false;

	friend class GameObjectList; // Allow GameObjectList to access private members

public:
	virtual void Update();
	virtual void Draw();
	void Delete();
};

