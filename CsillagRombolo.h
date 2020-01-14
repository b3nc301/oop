#pragma once
#include<string>
#include<iostream>	

class CsillagRombolo
{
protected:
	std::string Name;
	const int maxleg;
	const int minleg;
	int legszam;
	const int maxturlszam;
	const int minturlszam;
	int turlszam;
public:
	CsillagRombolo(std::string nev, int maxlszam, int minlszam, int lszam,int maxtlszam, int mintlszam, int turszam) :
		Name(nev), maxleg(maxlszam), minleg(minlszam), legszam(lszam),maxturlszam(maxlszam),minturlszam(mintlszam), turlszam(turszam) {};
	void addLegenyseg(int szam) {legszam+=szam;}
	void removeLegenyseg(int szam) { legszam-=szam; }
	unsigned int getLegenyseg() const {return legszam;}
	std::string getName() const { return Name; }
	void addLegenyseg(const unsigned int legenyseg) {legszam += legenyseg;}
	void removeLegenyseg(const unsigned int legenyseg) { legszam -= legenyseg; }
	bool checkUzemkepes() const { if (legszam >= minleg)return true; else return false; }
	unsigned int getMaxLegenyseg() const { return maxleg; }
	unsigned int getMinLegenyseg() const { return minleg; }


};

