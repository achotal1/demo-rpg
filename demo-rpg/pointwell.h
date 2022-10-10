#pragma once
#include <cstdint>
typedef std::uint16_t welltype;
class PointWell {
public:
	// if set successfully, returns true
	bool setMax(welltype new_MaxWell) {
		if (MaxWell < 1) {
			return false;
		}
		MaxWell = new_MaxWell;
		if (CurrentFullness > MaxWell) {
			CurrentFullness = MaxWell;
		}
		return true;
	}

	welltype getMax() {
		return MaxWell;
	}

	welltype getCurrentFullness() {
		return CurrentFullness;
	}

	void reduceCurrent(welltype damage) {
		if (damage > CurrentFullness) {
			CurrentFullness = 0;
			return;
		}
		CurrentFullness -= damage;

	}

	void increaseCurrent(welltype amount) {
		if (CurrentFullness == 0) {
			return;
		}
		if (CurrentFullness + amount > MaxWell) {
			CurrentFullness = MaxWell;
			return;
		}
		CurrentFullness += amount;
	}

	PointWell() {
		CurrentFullness = 1;
		MaxWell = 1;
	}
	PointWell(welltype c, welltype m) {
		CurrentFullness = c;
		MaxWell = m;
		if (CurrentFullness > MaxWell) {
			CurrentFullness = MaxWell;
		}
	}

private:
	welltype CurrentFullness;
	welltype MaxWell;
	//type shield;
};