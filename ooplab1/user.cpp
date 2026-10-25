#include "user.h"
#include "figure.h"

void User::look(Figure &c) {
	int n = c.petals();
	if (n == 1) {
		std::cout << "eta krug....ili evo chast..";
	}
	else {
		std::cout << "eta ne krug.....";
	};
}