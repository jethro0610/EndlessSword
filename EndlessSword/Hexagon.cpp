#include "Hexagon.h"
#include "GameWorld.h"
Hexagon::Hexagon() {
	SetImage("img/hexagon.png");
	scale = 50.0f;
}

Hexagon::~Hexagon() {
}

void Hexagon::Update() {
	Geo::Update();
	if (GetDistanceFromMouse() < 100.0f) {
		// Move away from mouse
		Move(position - GameWorld::GetWorld()->GetMousePosition());
	}
}