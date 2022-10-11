#pragma once
#include <cstdint>
typedef uint16_t stattype;
class StatBlock {

public:
	// explicit keyword to make sure only stattype is given to the constructor
	explicit StatBlock(stattype s = (stattype)1u, stattype i = (stattype)1u, stattype a = (stattype)1u, 
		stattype arm = (stattype)0u, stattype elemres = (stattype)0u) {
		Strength = s;
		Intellect = i;
		Agility = a;
		Armor = arm;
		ElementRes = elemres;
	}
	stattype getStrength() {
		return Strength;
	}
	stattype getIntellect() {
		return Intellect;
	}
	stattype getAgility() {
		return Agility;
	}
	stattype getArmor() {
		return Armor;
	}
	stattype getElementRes() {
		return ElementRes;
	}
protected:
	void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype elemres = 0) {
		Strength += s;
		Intellect += i;
		Agility += a;
		Armor += arm;
		ElementRes += elemres;

	}

private:
	stattype Strength;
	stattype Intellect;
	stattype Agility;
	stattype Armor;
	stattype ElementRes;

};