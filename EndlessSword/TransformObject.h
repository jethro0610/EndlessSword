#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL_stdinc.h>

class TransformObject: public GameObject {
public:
	TransformObject();
	~TransformObject();

	bool IsOverlapping(TransformObject* OtherObject);

public:
	Vector2D position;
	float scale = 20.0f;

protected:
	Vector2D GetDrawPosition();
};

