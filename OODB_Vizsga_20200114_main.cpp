
// Ez a resz a kivant szintnek megfeleloen valtoztathato (0 vagy 1)
#define SZINT_2 1
#define SZINT_3 1
#define SZINT_4 1
#define SZINT_5 0

// Ha fejleszt, erdemes kikapcsolni az ellenorzest
#define ELLENORZES 1

// A tesztek altal hasznalt konyvtarak
#include <iostream>
#include <cassert>

#include "csillagrombolo.h"
#include"Executor.h"
#include"Imperial.h"
#include"Flotta.h"

int main()
{
	std::cout << "VIZSGA 2020-01-14\n";

#if SZINT_2
	std::cout << "-------   2-es szint -----------\n";
	// Csillagrombolok peldanyositasa
	Imperial* vehement = new Imperial("Vehement", 37000, 80);
	Imperial* exactor =  new Imperial("Exactor", 32000, 70);
	Imperial* devastator = new Imperial("Devastator", 28000, 35);
	Executor* executor = new Executor("Executor", 290000, 2500, 250);	
#if ELLENORZES
	// Csillagrombolok ellenorzese
	std::cout << "Vehement legenysege: " << vehement->getLegenyseg() << ",\t elvart: 37 000\n";
	assert(vehement->getLegenyseg() == 37000);
	std::cout << "Exactor legenysege: " << exactor->getLegenyseg() << ",\t elvart: 32 000\n";
	assert(exactor->getLegenyseg() == 32000);	
	std::cout << "Devastator legenysege: " << devastator->getLegenyseg() << ",\t elvart: 28 000\n";
	assert(devastator->getLegenyseg() == 28000);
	std::cout << "Executor legenysege: " << executor->getLegenyseg() << ",\t elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	// Legenyseg hozzaadasa (Vehement)
	vehement->addLegenyseg(1000);
	std::cout << "Vehement legenysege (+1000): " << vehement->getLegenyseg() << ",\t elvart: 38000\n";
	assert(vehement->getLegenyseg()==38000);
	vehement->removeLegenyseg(1000);
	std::cout << "Vehement legenysege (-1000): " << vehement->getLegenyseg() << ",\t elvart: 37000\n";
	assert(vehement->getLegenyseg() == 37000);
	// Legenyseg hozzaadasa (Executor)
	executor->addLegenyseg(1000);
	std::cout << "Executor legenysege (+1000): " << executor->getLegenyseg() << ",\t elvart: 291 000\n";
	assert(executor->getLegenyseg() == 291000);
	executor->removeLegenyseg(1000);
	std::cout << "Executor legenysege (-1000): " << executor->getLegenyseg() << ",\t elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	// Mozgas ellenorzese
	std::cout << "Vehement warp-speed: " << vehement->mozgas() << ", elvart: 1.0\n";
	assert(vehement->mozgas() == 1.0);
	std::cout << "Exactor warp-speed: " << vehement->mozgas() << ", elvart: 1.0\n";
	assert(exactor->mozgas() == 1.0);
	std::cout << "Devastator warp-speed: " << vehement->mozgas() << ", elvart: 0.0\n";
	assert(devastator->mozgas() == 0.0);
	std::cout << "Executor warp-speed: " << vehement->mozgas() << ", elvart: 1.5\n";
	assert(executor->mozgas() == 1.5);
	// Sebzes ellenorzese
	assert(vehement->tuzero() == 100 * 80);
	assert(exactor->tuzero() == 100 * 70);
	assert(devastator->tuzero() == 0);
	assert(executor->tuzero() == 150 * 2500 + 250 * 1000);
	// Segedmetodusok ellenorzese
	assert(vehement->getMinLegenyseg() == 29000);
	assert(vehement->getMaxLegenyseg() == 45000);
	assert(executor->getMinLegenyseg() == 50000);
	assert(executor->getMaxLegenyseg() == 350000);
	// Uzemkepesseg
	std::cout << "Vehement uzemkepes: " << vehement->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(vehement->checkUzemkepes());
	std::cout << "Exactor uzemkepes: " << exactor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(exactor->checkUzemkepes());
	std::cout << "Devastator uzemkepes: " << devastator->checkUzemkepes() << ",\t Elvart: 0\n";
	assert(!devastator->checkUzemkepes());
	std::cout << "Executor uzemkepes: " << executor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(executor->checkUzemkepes());
#endif
	// Flotta peldanyositasa
	Flotta flotta;
#if ELLENORZES
	assert(flotta.getTartalekLegenyseg() == 0);
#endif
	// Csillagrombolok hozzaadasa
	flotta.addCsillagrombolo(vehement);
	flotta.addCsillagrombolo(exactor);
	flotta.addCsillagrombolo(devastator);
	flotta.addCsillagrombolo(executor);
	// Csillagrombolo kiolvasasa
#if ELLENORZES
	assert(flotta.getCsillagRombolo("Vehement") != nullptr);
	assert(flotta.getCsillagRombolo("Executor") != nullptr);
	assert(flotta.getCsillagRombolo("Exactor") != nullptr);
	assert(flotta.getCsillagRombolo("Devastator") != nullptr);
	assert(flotta.getCsillagRombolo("Millenium Falcon") == nullptr);
	assert(flotta.getCsillagRombolo("Vindicator") == nullptr);
#endif
	// Flotta tartalek legenyseg hozzaadasa
	flotta.addTartalekLegenyseg(20000);
#if ELLENORZES
	std::cout << "Flottahoz rendelt tartaleklegenyseg: " << flotta.getTartalekLegenyseg() << ", elvart legenyseg: 20 000\n";
	assert(flotta.getTartalekLegenyseg() == 20000);
#endif
	// Flotta ellenorzese
#if ELLENORZES
	std::cout << "Flottaban levo hajok: " << flotta.getQuantity() << ", elvart hajoszam: 4\n";
	assert(flotta.getQuantity() == 4);
	std::cout << "\n";
#endif

	std::cout << "Vehement legenysege (-1000): " << vehement->getLegenyseg() << ",\t elvart: 37000\n";

#if SZINT_3	
	std::cout << "-------   3-as szint -----------\n";
	flotta.addLegenyseg("Executor", 10000);
	std::cout << "Vehement legenysege (-1000): " << vehement->getLegenyseg() << ",\t elvart: 37000\n";
	flotta.addLegenyseg(vehement, 1000);
#if ELLENORZES
	std::cout << "Vehement legenysegenek feltoltese a tartalekbol (+1000): " << vehement->getLegenyseg() << ", elvart: 38 000\n";
	assert(vehement->getLegenyseg() == 38000);
	std::cout << "Executor legenysegenek feltoltese a tartalekbol (+10000): " << executor->getLegenyseg() << ", elvart: 300 000\n";
	assert(executor->getLegenyseg() == 300000);
	std::cout << "Maradek tartaleklegenyseg " << flotta.getTartalekLegenyseg() << ", 9 000\n";
	assert(flotta.getTartalekLegenyseg() == 9000);
#endif
	flotta.tartalekbaHelyez("Executor", 10000);
#if ELLENORZES
	// Tartalekba helyezes utan
	std::cout << "Tartalekba helyezes az executorrol (-10000): " << executor->getLegenyseg() << ", elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	assert(flotta.getTartalekLegenyseg() == 19000);
#endif
	// A szukseges legenyseg ellenorzese
	std::cout << "A flotta ellatasahoz szukseges legenyseg: " << flotta.getOsszesLegenyseg() << ", elvart teljes legenyseg: 407 000\n";
#if ELLENORZES
	assert(flotta.getOsszesLegenyseg() == 407000);
#endif
	std::cout << "\n";
#endif // SZINT_3


#if SZINT_4
	std::cout << "-------   4-es szint -----------\n";
	// Ellenorizzuk mukodokepes-e a flotta
	std::cout << "A flotta nem mukodik, nincs eleg legenyseg, a kovetkezo hajon nincs eleg legenyseg: " << flotta.checkImmobility()->getName() << '\n';
#if ELLENORZES
	assert(flotta.checkImmobility() != nullptr);
	assert(flotta.checkImmobility() == devastator);
#endif
	// Hibakezeles ellenorzes
	std::cout << "Eljarasok helyessegenek tesztelese: " << '\n';
	bool success;
	
	success = flotta.addLegenysegChecked(vehement, 15000);
	assert(!success); // tul sok legenyseg
	
	success = flotta.addLegenysegChecked(executor, 25000);
	assert(!success); // nincs eleg tartalekos
	
	success = flotta.tartalekbaHelyezChecked(executor, 250000);
	assert(!success); // minimalis ala csokkenne a legenyseg
	
	success = flotta.removeTartalekosChecked(90000);
	assert(!success); // nincs ennyi tartalekos
	
    // A metodusok tesztje utan adjunk hozza az egyetlen hianyzo hajohoz 
	// Ellenorizzuk mukodokepes-e a flotta
	std::cout << "Devastator potlasa megfelelo mennyisegu legenyseggel: (+2000)\n";
	success = flotta.addLegenysegChecked(devastator, 2000);
	assert(success);
	std::cout << "Devastator legenysege: " << devastator->getLegenyseg() << ", elvart legenyseg 30 000\n";
	assert(devastator->getLegenyseg() == 30000);
#if ELLENORZES
	assert(flotta.checkImmobility()==nullptr);

	std::cout << "A flotta mukodik, minden hajo uzemkepes" << '\n';
	std::cout << "\n";
#endif
#endif // SZINT_4


#if SZINT_5
	std::cout << "-------   5-os szint -----------\n";
	Imperial* vehement2 = new Imperial("Vehement", 2000, 80);
	assert(*vehement == *vehement2);
	flotta.addCsillagromboloChecked(vehement2);
#if ELLENORZES
	std::cout << "A flotta hajoszama: " << flotta.getQuantity() << ", elvart hajoszam: 4\n";
	assert(flotta.getQuantity()==4);
	std::cout << "A Vehement legenysege (+2000): " << vehement->getLegenyseg() << ", elvart legenyseg: 40000 \n";
	assert(vehement->getLegenyseg()==40000);
#endif
	std::cout << *vehement << '\n';
	std::cout << *executor << '\n';
	std::cout << flotta;
	std::cout << "\n";
	
	delete vehement2;
#endif // SZINT_5
	

	delete vehement;
	delete exactor;
	delete devastator;
	delete executor;
	
#endif // SZINT_2
	return 0;
}
