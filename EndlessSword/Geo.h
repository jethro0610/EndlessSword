#pragma once
#include "TransformObject.h"
class Geo : public TransformObject {
public:
	Geo();
	~Geo();

	void SetColor(Uint8 Red, Uint8 Green, Uint8 Blue);
	virtual void Update() override;
	void Move(Vector2D Direction);

	float GetDistanceFromMouse();

public:
	Vector2D velocity = Vector2D(0, 0);

protected:
	virtual void OnOutOfBounds();
	float GetAcceleration() { return (maxSpeed * friction) / (-friction + 1.0f); };

protected:
	float maxSpeed = 10.0f;
	float friction = 0.01f;

	Uint8 red = 255;
	Uint8 green = 255;
	Uint8 blue = 255;
};

