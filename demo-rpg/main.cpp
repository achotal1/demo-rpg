#include <iostream>
#include "allclasses.h"
using namespace std;
int main() {
	Wizard cle;
	for (int i = 0; i < 2; i++) {
		
		cout << "\nCleric\n" << "max HP:" << cle.getMaxHP()
			<< "\nStrength: " << cle.getStrength()
			<< "\nIntellect: " << cle.getIntellect()
			<< "\n Level: " << cle.getLevel()
			<< "\n EXP: " << cle.getCurrentEXP();
		cle.gainEXP(100u);
		
	}
	

		
	return 0;
}