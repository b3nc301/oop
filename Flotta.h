#pragma once
#include "CsillagRombolo.h"
#include"Executor.h"
#include"Imperial.h"
#include<vector>
#include<string>
#include <iostream>

class Flotta
{
	std::vector<CsillagRombolo*> csillagrombolok;
	int tartleg;

public:
	void addCsillagrombolo(CsillagRombolo* csr);
	CsillagRombolo* getCsillagRombolo(std::string nev);
	int getQuantity();
	void addTartalekLegenyseg(int szam);
	int getTartalekLegenyseg();
	void addLegenyseg(std::string nev, int szam);
	void addLegenyseg(CsillagRombolo* nev, int szam);
	void addLegenyseg(CsillagRombolo& nev, int szam);
	void tartalekbaHelyez(std::string nev, int szam);
	int getOsszesLegenyseg();
	CsillagRombolo* checkImmobility();
	bool addLegenysegChecked(CsillagRombolo* nev, int szam);
	bool tartalekbaHelyezChecked(CsillagRombolo* nev, int szam);
	bool removeTartalekosChecked(int szam);
	void addCsillagromboloChecked(CsillagRombolo* csr);
	CsillagRombolo* getCsillagRomboloByNum(int num);
	std::vector<CsillagRombolo*> GetCsillagRombolok();
};
std::ostream& operator<<(std::ostream&, Flotta&);
