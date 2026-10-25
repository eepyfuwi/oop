#include <matplot/matplot.h>
#include <cmath>
#include "figure.h"
#include "user.h"
#include <iostream>
#include <vector>

int main() {
	using namespace matplot;
	Figure rose1{ 2,3 };
	Figure circle{ 2,1 };
	Figure sector{0,2*pi,0.1,1};
	sector.draw();
	std::cout << sector.length() << "\n";
	User debil;
	debil.look(sector);
   return 0;
}