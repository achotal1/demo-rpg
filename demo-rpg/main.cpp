#include <iostream>
#include "playercharacter.h"
using namespace std;
int main() {
	PlayerCharacter p1(new Cleric());
	for (int i = 0; i < 2; i++) {
		
		cout << '\n' << p1.getClassName()
			<< "\n" << "HP:" << p1.getCurrentHP() << '/' << p1.getMaxHP()
			<< "\nStrength: " << p1.getStrength()
			<< "\nIntellect: " << p1.getIntellect()
			<< "\n Level: " << p1.getLevel()
			<< "\n EXP: " << p1.getCurrentEXP();
		
		if(i<1)
			p1.gainEXP(100u);
		
	}
	

		
	return 0;
}