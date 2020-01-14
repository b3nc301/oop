#pragma once
#include "CsillagRombolo.h"
#include <string>

class Imperial :
	public CsillagRombolo
{
	const double speed = 1.0;
public:
	Imperial(std::string n, int lsz, int tl) :
		CsillagRombolo(n, 45000, 29000, lsz, 80, 40, tl) {
	};
	double mozgas() {
		if (legszam >= minleg && legszam <= maxleg)
			return speed;
		else return 0.0;
	}
	int tuzero(){
			if (legszam >= minleg && legszam <= maxleg)
			return 100*turlszam;
			else return 0;
	}
};

