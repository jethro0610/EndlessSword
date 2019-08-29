#pragma once
#include "TransformObject.h"
class GeoHole : public TransformObject {
public:
	GeoHole();
	~GeoHole();

	void Update() override;
	void Draw() override;
};

