#include "TransformObject.h"
#include "GameWorld.h"
#include <iostream>

TransformObject::TransformObject() {
	if (imagePath != "") {
		surface = SDL_LoadBMP(imagePath.c_str());
		texture = SDL_CreateTextureFromSurface(GameWorld::GetWorld()->GetRenderer(), surface);
		SDL_FreeSurface(surface);
	}
}

TransformObject::~TransformObject() {
}

bool TransformObject::IsOverlapping(TransformObject* OtherObject) {
	// Don't return true if the object is this one
	if (OtherObject == this)
		return false;

	// Check if objects are overlapping one another using a circle
	if (position.GetDistance(OtherObject->position) <= (scale / 2) + (OtherObject->scale/2)) {
		return true;
	}
	else {
		return false;
	}
}

std::vector<TransformObject*> TransformObject::GetAllOverlaps() {
	// Check overlap on all transform objects in the world
	GameObject* currentObject = GameWorld::GetWorld()->GetFirstObject();
	std::vector<TransformObject*> returnList;
	while (currentObject != nullptr) {
		// Cast to TransformObject
		TransformObject* transformObject = dynamic_cast<TransformObject*>(currentObject);

		// Cast is always null if the object is not of the desired type
		if (transformObject != nullptr) {
			if (IsOverlapping(transformObject)) {
				returnList.push_back(transformObject); // Add to list if the object is overlapping
			}
		}

		if (currentObject != GameWorld::GetWorld()->GetLastObject() && currentObject->GetNext() != nullptr) {
			currentObject = currentObject->GetNext();
		}
		else {
			break; // Stop loop if at the last object
		}
	}

	return returnList;
}

Vector2D TransformObject::GetDrawPosition() {
	// Return position that is centered based on scale
	return Vector2D(position.x - (scale / 2), position.y - (scale / 2));
}

void TransformObject::Draw() {
	if (imagePath != "") {
		SDL_Rect renderRect;

		renderRect.x = GetDrawPosition().x;
		renderRect.y = GetDrawPosition().y;
		renderRect.w = scale;
		renderRect.h = scale;

		SDL_RenderCopy(GameWorld::GetWorld()->GetRenderer(), texture, nullptr, &renderRect);
	}
}
