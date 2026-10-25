#pragma once
#include <matplot/matplot.h>
#include <cmath>
#include <iostream>
#include <vector>

class Figure {
public:
	Figure(float a1, float b1, float r1, int n1);
	Figure(float r1, int n1);
	Figure(float a1, float b1, float r1);
	void draw() const;
	Figure operator-() const;
	int petals() const;
	float area() const;
	float length() const;
	bool operator==(const Figure& other) const;
	bool operator!=(const Figure& other) const;
	bool operator< (const Figure& other) const;
	bool operator> (const Figure& other) const;
private:
	float a;
	float b;
	float r;
	int n;
};

