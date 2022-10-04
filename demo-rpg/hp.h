#pragma once
#include "hitpointtypes.h"

class hp {
public:
	// if set successfully, returns true
	bool setMaxHP(hptype new_max_hp) {
		if (maxHP < 1) {
			return false;
		}
		maxHP = new_max_hp;
		if (currentHP > maxHP) {
			currentHP = maxHP;
		}
		return true;
	}

	hptype getMaxHP() {
		return maxHP;
	}

	hptype getCurrentHP() {
		return currentHP;
	}

	void takeDamage(hptype damage) {
		if (damage > currentHP) {
			currentHP = 0;
			return;
		}
		currentHP -= damage;

	}

	void heal(hptype healamount) {
		if (currentHP == 0) {
			return;
		}
		if (currentHP + healamount > maxHP) {
			currentHP = maxHP;
			return;
		}
		currentHP += healamount;
	}

	hp() {
		currentHP = 1;
		maxHP = 1;
	}
	hp(hptype cHP, hptype mHP) {
		currentHP = cHP;
		maxHP = mHP;
		if (currentHP > maxHP) {
			currentHP = maxHP;
		}
	}

private:
	hptype currentHP;
	hptype maxHP;
	hptype shieldHP;
};