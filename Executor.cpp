#include "Executor.h"

Executor::Executor(std::string n, int lsz, int tl, int ionagyu) :
	CsillagRombolo(n, 350000, 50000, lsz, 1500, 2500, tl), minion(200), maxion(300), ion(ionagyu) {
};


double Executor::mozgas() {
	if (legszam >= minleg && legszam <= maxleg)
		return speed;
	else return 0.0;
}

int Executor::tuzero() {
	if (legszam >= minleg && legszam <= maxleg)
		return 150 * turlszam + 1000 * ion;
	else return 0;
}



