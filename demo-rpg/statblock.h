#pragma once
#include <cstdint>
typedef uint16_t stattype;
class StatBlock {

public:

	StatBlock() {
		Strength = (stattype)1u;
		Intellect = (stattype)1u;
	}
	// explicit keyword to make sure only stattype is given to the constructor
	explicit StatBlock(stattype s, stattype i) {
		Strength = s;
		Intellect = i;
	}
	stattype getStrength() {
		return Strength;
	}
	stattype getIntellect() {
		return Intellect;
	}
protected:
	void increaseStats(stattype s, stattype i) {
		Strength += s;
		Intellect += i;
	}

private:
	stattype Strength;
	stattype Intellect;

};