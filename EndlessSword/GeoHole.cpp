#include "GeoHole.h"
#include "Geo.h"
#include "GameWorld.h"
#include <vector>

GeoHole::GeoHole() {
	scale = 100.0f;
}


GeoHole::~GeoHole() {
}

void GeoHole::Update() {
	std::vector<TransformObject*> overlapList = GetAllOverlaps();
	// Loop through all overlaps
	for (int i = 0; i < overlapList.size(); i++){
		Geo* geoCast = dynamic_cast<Geo*>(overlapList[i]);
		if (geoCast != nullptr) { // If the overlap is a Geo...
			geoCast->Delete();
		}
	}
}

void GeoHole::Draw() {

}
