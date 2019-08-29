#include "Octagon.h"

Octagon::Octagon() {
	SetImage("img/octagon.png");
	scale = 50.0f;
}

Octagon::~Octagon() {
}

void Octagon::Update() {
	Geo::Update();

	std::vector<TransformObject*> overlapList = GetAllOverlaps();
	// Loop through all overlaps
	for (int i = 0; i < overlapList.size(); i++) {
		Geo* geoCast = dynamic_cast<Geo*>(overlapList[i]);
		if (geoCast != nullptr) { // If the overlap is a Geo...
			velocity = (position - geoCast->position).GetUnitVector() * 5.0f; // Shoot away from touch
		}
	}
}
