#pragma once
#include "CsillagRombolo.h"

class Executor : public CsillagRombolo
{
	const int minion;
	const int maxion;
	int ion;
	const double speed = 1.5;
public:
	Executor(std::string n, int lsz, int tl, int ionagyu);
	double mozgas();
	int tuzero();
};

