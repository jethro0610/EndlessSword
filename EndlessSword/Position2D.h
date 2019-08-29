#pragma once
#include <math.h>

struct Position2D {
	float x = 0;
	float y = 0;

	Position2D() {
		x = 0;
		y = 0;
	}

	Position2D(float X, float Y) {
		x = X;
		y = Y;
	}

	// Distance formula
	float GetDistance(Position2D OtherPosition) {
		float xDist = pow((OtherPosition.x - x), 2.0f);
		float yDist = pow((OtherPosition.y - y), 2.0f);
		return sqrt(xDist + yDist);
	}

	// Add two positions
	Position2D operator+(const Position2D& OtherPosition) {
		return Position2D(x + OtherPosition.x, y + OtherPosition.y);
	}
	Position2D operator+=(const Position2D& OtherPosition) {
		x += OtherPosition.x;
		y += OtherPosition.y;
	}

	// Subtract two positions
	Position2D operator-(const Position2D& OtherPosition) {
		return Position2D(x - OtherPosition.x, y - OtherPosition.y);
	}
	Position2D operator-=(const Position2D& OtherPosition) {
		x -= OtherPosition.x;
		y -= OtherPosition.y;
	}

	// Multiply a position by a float
	Position2D operator*(const float& MultiplyFloat) {
		return Position2D(x * MultiplyFloat, y * MultiplyFloat);
	}
	Position2D operator*=(const Position2D& OtherPosition) {
		x *= OtherPosition.x;
		y *= OtherPosition.y;
	}

	// Divide a position by a float
	Position2D operator/(const float& DivideFloat) {
		return Position2D(x / DivideFloat, y / DivideFloat);
	}
	Position2D operator/=(const Position2D& OtherPosition) {
		x /= OtherPosition.x;
		y /= OtherPosition.y;
	}
};

