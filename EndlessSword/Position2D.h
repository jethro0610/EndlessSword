#pragma once

struct Position2D {
	float x = 0;
	float y = 0;

	Position2D(float X, float Y) {
		x = X;
		y = Y;
	}

	// Add two positions
	Position2D operator+(const Position2D& OtherPosition) {
		return Position2D(x + OtherPosition.x, y + OtherPosition.y);
	}

	// Subtract two positions
	Position2D operator-(const Position2D& OtherPosition) {
		return Position2D(x - OtherPosition.x, y - OtherPosition.y);
	}

	// Multiply a position by a float
	Position2D operator*(const float& MultiplyFloat) {
		return Position2D(x * MultiplyFloat, y * MultiplyFloat);
	}

	// Divide a position by a float
	Position2D operator/(const float& DivideFloat) {
		return Position2D(x / DivideFloat, y / DivideFloat);
	}
};

