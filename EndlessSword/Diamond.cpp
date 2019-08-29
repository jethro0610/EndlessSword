#include "Diamond.h"
#include "GameWorld.h"

Diamond::Diamond() {
	SetImage("img/diamond.png");
	scale = 50.0f;
}

Diamond::~Diamond() {
}

void Diamond::Update() {
	Geo::Update();
	if (GetDistanceFromMouse() < 200.0f) {
		// Move toward mouse
		Move(GameWorld::GetWorld()->GetMousePosition() - position);
	}
}
