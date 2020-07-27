#include "Flotta.h"

void Flotta::addCsillagrombolo(CsillagRombolo* csr) {
	csillagrombolok.push_back(csr);
}


CsillagRombolo * Flotta::getCsillagRombolo(std::string nev) {
	for (int i = 0; i < csillagrombolok.size(); i++)
	{
		if (csillagrombolok[i]->getName() == nev)
			return csillagrombolok[i];
	}
	return nullptr;
}
int Flotta::getQuantity() {
	return csillagrombolok.size();
}

void Flotta::addTartalekLegenyseg(int szam) {
	tartleg += szam;
}

int Flotta::getTartalekLegenyseg() {
	return tartleg;
}

void Flotta::addLegenyseg(std::string nev, int szam) {
	for (int i = 0; i < csillagrombolok.size(); i++)
	{
		if (csillagrombolok[i]->getName() == nev)
		{
			csillagrombolok[i]->addLegenyseg(szam);
			tartleg -= szam;
		}
	}
}

void Flotta::addLegenyseg(CsillagRombolo* nev, int szam) {
		for (int i = 0; i < csillagrombolok.size(); i++)
		{
			if (csillagrombolok[i]->getName() == nev->getName())
			{
				csillagrombolok[i]->addLegenyseg(szam);
				tartleg -= szam;
			}
		}
	}


void Flotta::addLegenyseg(CsillagRombolo& nev, int szam) {
		for (int i = 0; i < csillagrombolok.size(); i++)
		{
			if (csillagrombolok[i]->getName() == nev.getName())
			{
				csillagrombolok[i]->addLegenyseg(szam);
				tartleg -= szam;
			}
		}
}



void Flotta::tartalekbaHelyez(std::string nev, int szam) {
	for (int i = 0; i < csillagrombolok.size(); i++)
	{
		if (csillagrombolok[i]->getName() == nev)
		{
			csillagrombolok[i]->removeLegenyseg(szam);
			tartleg += szam;
		}
	}
}

int Flotta::getOsszesLegenyseg() {
	int letszam = 0;
	for (int i = 0; i < csillagrombolok.size(); i++) {
		letszam += csillagrombolok[i]->getLegenyseg();
	}
	letszam += tartleg;
	return letszam;
}


CsillagRombolo* Flotta::checkImmobility() {
	for (int i = 0; i < csillagrombolok.size(); i++) {
		if (!csillagrombolok[i]->checkUzemkepes())
		{
			return csillagrombolok[i];
		}
	}
	return nullptr;
}

bool Flotta::addLegenysegChecked(CsillagRombolo* nev, int szam) {
	for (int i = 0; i < csillagrombolok.size(); i++)
	{
		if (csillagrombolok[i]->getName() == nev->getName() && ((csillagrombolok[i]->getLegenyseg() + szam) <= csillagrombolok[i]->getMaxLegenyseg()) && (getTartalekLegenyseg() - szam > 0))
		{
			csillagrombolok[i]->addLegenyseg(szam);
			tartleg -= szam;
			return true;
		}
	}
	return false;
}

bool Flotta::tartalekbaHelyezChecked(CsillagRombolo* nev, int szam) {
	for (int i = 0; i < csillagrombolok.size(); i++)
	{
		if (csillagrombolok[i]->getName() == nev->getName() && (csillagrombolok[i]->getLegenyseg() - szam) >= csillagrombolok[i]->getMinLegenyseg())
		{
			csillagrombolok[i]->removeLegenyseg(szam);
			tartleg += szam;
			return true;
		}
		return false;
	}
}

bool Flotta::removeTartalekosChecked(int szam) {
	if (getTartalekLegenyseg() - szam < 0)
		return false;
	else {
		tartleg -= szam;
		return true;
	}
}

void Flotta::addCsillagromboloChecked(CsillagRombolo* csr) {
	for (int i = 0; i < csillagrombolok.size(); i++) {
		if (*csillagrombolok[i] == *csr) {
			csillagrombolok[i]->addLegenyseg(csr->getLegenyseg());
			return;
		}
	}
	csillagrombolok.push_back(csr);
};

CsillagRombolo* Flotta::getCsillagRomboloByNum(int num)
{
	return csillagrombolok[num];
};
std::ostream& operator<<(std::ostream& out, Flotta& fl)
{
	out << "Flotta: \n";
	for (int i = 0; i < fl.getQuantity(); i++) {
		out << *(fl.getCsillagRomboloByNum(i)) << "\n";
	}
	return out;
}

