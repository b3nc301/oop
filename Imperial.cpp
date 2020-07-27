#include "Imperial.h"

Imperial::Imperial(std::string n, int lsz, int tl) :
	CsillagRombolo(n, 45000, 29000, lsz, 80, 40, tl) {
};


double Imperial::mozgas() {
	if (legszam >= minleg && legszam <= maxleg)
		return speed;
	else return 0.0;
}

int Imperial::tuzero() {
	if (legszam >= minleg && legszam <= maxleg)
		return 100 * turlszam;
	else return 0;
}


