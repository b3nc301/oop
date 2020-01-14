#pragma once
#include "CsillagRombolo.h"
#include"Executor.h"
#include"Imperial.h"
#include<vector>
#include<string>


class Flotta
{
	std::vector<CsillagRombolo*> csillagrombolok;
	int tartleg;

public:
	void addCsillagrombolo(CsillagRombolo* csr) { csillagrombolok.push_back(csr); }

	CsillagRombolo * getCsillagRombolo(std::string nev) {
		for(int i=0;i<csillagrombolok.size();i++)
		{
			if (csillagrombolok[i]->getName() == nev)
				return csillagrombolok[i];
		}
		return nullptr;
	}
	int getQuantity() {
		return csillagrombolok.size();
	}
	void addTartalekLegenyseg(int szam) { tartleg += szam; }
	int getTartalekLegenyseg() { return tartleg; }

		void addLegenyseg(std::string nev, int szam) {
			for (int i = 0; i < csillagrombolok.size(); i++)
			{
				if (csillagrombolok[i]->getName() == nev)
				{
					csillagrombolok[i]->addLegenyseg(szam);
					tartleg -= szam;
				}
			}
	}

		void addLegenyseg(CsillagRombolo* nev, int szam) {
			CsillagRombolo* pro = dynamic_cast<CsillagRombolo*>(nev);
			if (pro != nullptr)
			{
				for (int i = 0; i < csillagrombolok.size(); i++)

				{
					if (csillagrombolok[i]->getName() == nev->getName())
					{csillagrombolok[i]->addLegenyseg(szam);
					tartleg -= szam; }
				}
			}
		}

		void addLegenyseg(CsillagRombolo& nev, int szam) {
			try {
				CsillagRombolo& pro = dynamic_cast<CsillagRombolo&>(nev);
				for (int i = 0; i < csillagrombolok.size(); i++)
				{
					if (csillagrombolok[i]->getName() == nev.getName())
					{
						csillagrombolok[i]->addLegenyseg(szam);
						tartleg -= szam;
					}
				}
			}
			catch (std::bad_cast& ex) {
			}
			
		}
		void tartalekbaHelyez(std::string nev, int szam) {
				for (int i = 0; i < csillagrombolok.size(); i++)
				{
					if (csillagrombolok[i]->getName() == nev)
					{
						csillagrombolok[i]->removeLegenyseg(szam);
						tartleg += szam;
					}
				}
			}
		int getOsszesLegenyseg() {
			int lszam=0;
			for (int i = 0; i < csillagrombolok.size(); i++) {
				lszam += csillagrombolok[i]->getLegenyseg();
			}
			lszam += tartleg;
			return lszam;
		}


		CsillagRombolo* checkImmobility() {
			CsillagRombolo* a=nullptr;
			for (int i = 0; i < csillagrombolok.size(); i++) {
				if (csillagrombolok[i]->checkUzemkepes() == true)
				{
				}
				else {
					a = csillagrombolok[i];
						break;
				}
			}
			return a;
		}


		bool addLegenysegChecked(CsillagRombolo* nev, int szam) {
			for (int i = 0; i < csillagrombolok.size(); i++)

			{
				if (csillagrombolok[i]->getName() == nev->getName() && ((csillagrombolok[i]->getLegenyseg() + szam) <= csillagrombolok[i]->getMaxLegenyseg()) && ( getTartalekLegenyseg()-szam > 0))
				{
					csillagrombolok[i]->addLegenyseg(szam);
					tartleg -= szam;
					return true;
				}
				
			}return false;


		}

		bool tartalekbaHelyezChecked(CsillagRombolo* nev, int szam) {
			for (int i = 0; i < csillagrombolok.size(); i++)
			{
				if (csillagrombolok[i]->getName() == nev->getName() && (csillagrombolok[i]->getLegenyseg() - szam) >= csillagrombolok[i]->getMinLegenyseg())
				{
					csillagrombolok[i]->removeLegenyseg(szam);
					tartleg += szam;
					return true;
					break;
				}
				return false;

			}
		}
		bool removeTartalekosChecked(int szam) {
			if (getTartalekLegenyseg() - szam < 0)
				return false;
			else {
				tartleg -= szam;
				return true;
			}
		}


};

