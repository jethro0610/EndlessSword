#pragma once
#include "Geo.h"
class Octagon : public Geo {
public:
	Octagon();
	~Octagon();

	virtual void Update() override;
};

