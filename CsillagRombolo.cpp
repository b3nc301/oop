#include "CsillagRombolo.h"

CsillagRombolo::CsillagRombolo(std::string nev, int maxlszam, int minlszam, int lszam, int maxtlszam, int mintlszam, int turszam) :
	Name(nev), maxleg(maxlszam), minleg(minlszam), legszam(lszam), maxturlszam(maxlszam), minturlszam(mintlszam), turlszam(turszam) 
{};


void CsillagRombolo::addLegenyseg(int szam) {
	legszam += szam;
}

void CsillagRombolo::removeLegenyseg(int szam) {
	legszam -= szam;
}

unsigned int CsillagRombolo::getLegenyseg() const {
	return legszam;
}

std::string CsillagRombolo::getName() const {
	return Name;
}

void CsillagRombolo::addLegenyseg(const unsigned int legenyseg) {
	legszam += legenyseg;
}

void CsillagRombolo::removeLegenyseg(const unsigned int legenyseg) {
	legszam -= legenyseg;
}

bool CsillagRombolo::checkUzemkepes() const {
	if (legszam >= minleg)
		return true; 
	else return false;
}

unsigned int CsillagRombolo::getMaxLegenyseg() const {
	return maxleg;
}

unsigned int CsillagRombolo::getMinLegenyseg() const {
	return minleg;
}

bool CsillagRombolo::operator==(CsillagRombolo& other) {
	return getName()==this->getName();
}

std::ostream& operator<<(std::ostream& out, const CsillagRombolo& csr)
{
	out << "Nev:" << csr.getName() << " Legenyseg:" << csr.getLegenyseg() << " Min. legenyseg:"<< csr.getMinLegenyseg() << " Max. legenyseg:" <<  csr.getMaxLegenyseg();
	return out;
}
