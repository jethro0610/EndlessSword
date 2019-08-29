#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL_stdinc.h>
#include <SDL_image.h>
#include <vector>
#include <string>

class TransformObject: public GameObject {
public:
	TransformObject();
	~TransformObject();

	bool IsOverlapping(TransformObject* OtherObject);
	std::vector<TransformObject*> GetAllOverlaps();

	virtual void Draw() override;

public:
	Vector2D position;
	float scale = 20.0f;

protected:
	std::string imagePath = "";

protected:
	Vector2D GetDrawPosition();

private:
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
};

