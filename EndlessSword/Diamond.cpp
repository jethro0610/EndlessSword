#include "Diamond.h"
#include "GameWorld.h"

Diamond::Diamond() {
	SetImage("img/diamond.png");
	scale = 50.0f;
	maxSpeed = 0.001f;
}

Diamond::~Diamond() {
}

void Diamond::Update() {
	Geo::Update();
	if (GetDistanceFromMouse() < 100.0f) {
		// Move toward mouse
		Move(GameWorld::GetWorld()->GetMousePosition() - position);
	}
}
