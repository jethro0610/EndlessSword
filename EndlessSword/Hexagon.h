#pragma once
#include "Geo.h"
class Hexagon : public Geo{
public:
	Hexagon();
	~Hexagon();

	virtual void Update() override;
};

