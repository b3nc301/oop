#pragma once
#include "CsillagRombolo.h"
#include <string>

class Imperial : public CsillagRombolo
{
	const double speed = 1.0;
public:
	Imperial(std::string n, int lsz, int tl);
	double mozgas();
	int tuzero();
};

