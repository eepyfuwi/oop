#include "figure.h"

Figure::Figure(float a1, float b1, float r1, int n1) {
	a = a1;
	b = b1;
	r = r1;
	n = n1;
}
Figure::Figure(float r1, int n1): Figure(0, 2 * matplot::pi, r1, n1) {}
Figure::Figure(float a1, float b1, float r1): Figure(a1, b1,r1,1) {}

void Figure::draw() const{
	using namespace matplot;

	std::vector<double> theta = linspace(a, b, 1000);
	std::vector<double> rho = transform(theta, [this](auto t) { return (r * cos(n * t)); });

	polarplot(theta, rho)->line_width(2);
	show();
}


Figure Figure::operator-() const {
	Figure result = *this;
	result.r = -r;
	return result;
}

int Figure::petals() const {
	return (n % 2 == 0) ? 2 * n : n;
}

bool Figure::operator==(const Figure& other) const {
	return petals() == other.petals();
}

bool Figure::operator!=(const Figure& other) const {
	return petals() != other.petals();
}

bool Figure::operator<(const Figure& other) const {
	return petals() < other.petals();
}

bool Figure::operator>(const Figure& other) const {
	return petals() > other.petals();
}

float Figure::area() const {
	if (n % 2 == 0) {
		return matplot::pi * r * r / 2.0;
	}
	return matplot::pi * r * r / 4.0;
}

float Figure::length() const {
	if (n == 1) {
		return (b - a) * r;
	}
	else return 0;
}