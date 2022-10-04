#include <iostream>
#include "allclasses.h"
using namespace std;
int main() {
	Warrior warr1;
	Wizard wiz1;
	Cleric cle1;
	Rogue rog1;
	cout << "Warrior\n" << "max HP:" << warr1.getMaxHP()
		<< "\nStrength: " << warr1.getStrength()
		<< "\nIntellect: " << warr1.getIntellect();
	cout << "\nWizard\n" << "max HP:" << wiz1.getMaxHP()
		<< "\nStrength: " << wiz1.getStrength()
		<< "\nIntellect: " << wiz1.getIntellect();
	cout << "\nCleric\n" << "max HP:" << cle1.getMaxHP()
		<< "\nStrength: " << cle1.getStrength()
		<< "\nIntellect: " << cle1.getIntellect();
	cout << "\nRogue\n" << "max HP:" << rog1.getMaxHP()
		<< "\nStrength: " << rog1.getStrength()
		<< "\nIntellect: " << rog1.getIntellect();

		
	return 0;
}