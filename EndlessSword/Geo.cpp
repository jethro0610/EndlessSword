#include "Geo.h"
#include "GameWorld.h"
#include <iostream>;

Geo::Geo() {
}

Geo::~Geo() {
}

void Geo::SetColor(Uint8 Red, Uint8 Green, Uint8 Blue) {
	red = Red;
	green = Green;
	blue = Blue;
}

void Geo::Update() {
	// Eases velocity to zero
	velocity -= velocity * friction;

	// Change position based on velocity
	position += velocity;

	// Detect out of bounds
	if (position.x < 0.0f - (scale / 2)) {
		OnOutOfBounds();
	}
	else if (position.x > GameWorld::GetWorld()->GetWidth() + (scale / 2)) {
		OnOutOfBounds();
	}
	else if (position.y < 0.0f - (scale / 2)) {
		OnOutOfBounds();
	}
	else if (position.y > GameWorld::GetWorld()->GetHeight() + (scale / 2)) {
		OnOutOfBounds();
	}
}

void Geo::Move(Vector2D Direction) {
	// Add velocity in desired move direciton
	velocity += Direction.GetUnitVector() * GetAcceleration();
}

void Geo::OnOutOfBounds() {
	std::cout << "oob" << std::endl;
	Delete();
}
