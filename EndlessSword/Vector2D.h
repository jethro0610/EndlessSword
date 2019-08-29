#pragma once
#include <math.h>

struct Vector2D {
	float x = 0;
	float y = 0;

	Vector2D() {
		x = 0;
		y = 0;
	}

	Vector2D(float X, float Y) {
		x = X;
		y = Y;
	}

	// Distance formula
	float GetDistance(Vector2D OtherVector) {
		float xDist = pow((OtherVector.x - x), 2.0f);
		float yDist = pow((OtherVector.y - y), 2.0f);
		return sqrt(xDist + yDist);
	}

	float GetMagnitude() {
		float xSqr = pow(x, 2.0f);
		float ySqr = pow(y, 2.0f);
		return sqrt(xSqr + ySqr);
	}

	Vector2D GetUnitVector() {
		return Vector2D(x / GetMagnitude(), y / GetMagnitude());
	}

	// Add two Vectors
	Vector2D operator+(const Vector2D& OtherVector) {
		return Vector2D(x + OtherVector.x, y + OtherVector.y);
	}
	void operator+=(const Vector2D& OtherVector) {
		x += OtherVector.x;
		y += OtherVector.y;
	}

	// Subtract two Vectors
	Vector2D operator-(const Vector2D& OtherVector) {
		return Vector2D(x - OtherVector.x, y - OtherVector.y);
	}
	void operator-=(const Vector2D& OtherVector) {
		x -= OtherVector.x;
		y -= OtherVector.y;
	}

	// Multiply a Vector by a float
	Vector2D operator*(const float& MultiplyFloat) {
		return Vector2D(x * MultiplyFloat, y * MultiplyFloat);
	}
	void operator*=(const Vector2D& OtherVector) {
		x *= OtherVector.x;
		y *= OtherVector.y;
	}

	// Divide a Vector by a float
	Vector2D operator/(const float& DivideFloat) {
		return Vector2D(x / DivideFloat, y / DivideFloat);
	}
	void operator/=(const Vector2D& OtherVector) {
		x /= OtherVector.x;
		y /= OtherVector.y;
	}
};

