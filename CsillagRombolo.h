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
	CsillagRombolo(std::string nev, int maxlszam, int minlszam, int lszam, int maxtlszam, int mintlszam, int turszam);
	void addLegenyseg(int szam);
	void removeLegenyseg(int szam);
	unsigned int getLegenyseg() const;
	std::string getName() const;
	void addLegenyseg(const unsigned int legenyseg);
	void removeLegenyseg(const unsigned int legenyseg);
	bool checkUzemkepes() const;
	unsigned int getMaxLegenyseg() const;
	unsigned int getMinLegenyseg() const;
	bool operator==(CsillagRombolo& other);
};
std::ostream& operator<<(std::ostream&, const CsillagRombolo&);

