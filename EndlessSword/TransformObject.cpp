#include "TransformObject.h"
#include "GameWorld.h"
#include <iostream>

TransformObject::TransformObject() {
}

TransformObject::~TransformObject() {
}

bool TransformObject::IsOverlapping(TransformObject* OtherObject) {
	// Check if objects are overlapping one another using a circle
	if (position.GetDistance(OtherObject->position) <= (scale / 2) + (OtherObject->scale/2)) {
		return true;
	}
	else {
		return false;
	}
}

Vector2D TransformObject::GetDrawPosition() {
	// Return position that is centered based on scale
	return Vector2D(position.x - (scale / 2), position.y - (scale / 2));
}
