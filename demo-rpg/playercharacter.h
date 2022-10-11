#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointwell.h"
#include <memory>
#include<string>
typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;

class PlayerCharacterDelegate: public StatBlock{
public:
	static const exptype LEVEL2AT = 100u;
	PlayerCharacterDelegate(): StatBlock(0u, 0u) {
		CurrentLevel = 1u;
		CurrentEXP = 0u;
		EXPToNextLevel = LEVEL2AT;
		HP = std::make_unique<PointWell>();

	}

	void gainEXP( exptype gained_exp) {
		CurrentEXP += gained_exp;
		while (check_if_leveled()) {}
	}
	
	leveltype getLevel() {
		return CurrentLevel;
	}

	exptype getCurrentEXP() {
		return CurrentEXP; 
	}

	exptype getEXPToNextLevel() {
		return EXPToNextLevel;
	}

	virtual void LevelUp() = 0;
	virtual std::string getClassName() = 0;

	std::unique_ptr<PointWell> HP;


protected:
	leveltype CurrentLevel;
	exptype CurrentEXP;
	exptype EXPToNextLevel;

	bool check_if_leveled() {
		static const exptype LEVELSCALAR = 2u;
		if (CurrentEXP >= EXPToNextLevel) {
			CurrentLevel++;
			LevelUp();
			EXPToNextLevel *= LEVELSCALAR;
			return true;
		}
		return false;

	}
};
// Player Character Constructor 
#define PCCONSTRUCT : PlayerCharacterDelegate() {\
HP->setMax(BASEHP);\
HP->increaseCurrent(BASEHP);\
increaseStats(BASESTR, BASEINT, BASEAGI);\
}

#define LEVELUP void LevelUp() override {\
welltype hp = HP->getMax() + (welltype)(BASEHP / 2.f);\
HP->setMax(hp);\
HP->increaseCurrent((welltype)(BASEHP / 2.f));\
increaseStats((stattype)((BASESTR + 1u) / 2.f), (stattype)((BASEINT + 1u) / 2.f), (stattype)((BASEINT + 1u) / 2.f));\
}

#define CHARACTERCLASS(classname, basehp, basestr, baseint, baseagi)\
class classname : public PlayerCharacterDelegate {\
public:\
	static const welltype BASEHP = (welltype)basehp;\
	static const stattype BASESTR = (stattype)basestr;\
	static const stattype BASEINT = (stattype)baseint;\
	static const stattype BASEAGI = (stattype)baseagi;\
\
	classname() PCCONSTRUCT\
	std::string getClassName() override {\
		return std::string(#classname);\
	}\
private:\
	LEVELUP\
};


CHARACTERCLASS(Cleric, 14, 3, 5, 1);
CHARACTERCLASS(Wizard, 10, 1, 8, 1);
CHARACTERCLASS(Warrior, 20, 5, 2, 2);
CHARACTERCLASS(Rogue, 14, 4, 4, 5);


class PlayerCharacter {
private:
	PlayerCharacterDelegate* pcclass;
public:
	PlayerCharacter() = delete; // so no one tries to use default
	PlayerCharacter(PlayerCharacterDelegate* pc):pcclass(pc) {}
	std::string getClassName() {
		return pcclass->getClassName();
	}
	welltype getMaxHP() {
		return pcclass->HP->getMax();
	}
	welltype getCurrentHP() {
		return pcclass->HP->getCurrentFullness();
	}
	stattype getStrength() {
		return pcclass->getStrength();
	}
	stattype getIntellect() {
		return pcclass->getIntellect();
	}
	stattype getAgility() {
		return pcclass->getAgility();
	}
	stattype getArmor() {
		return pcclass->getArmor();
	}
	leveltype getElementRes() {
		return pcclass->getElementRes();
	}
	exptype getCurrentEXP() {
		return pcclass->getCurrentEXP();
	}
	void gainEXP(exptype amt) {
		pcclass->gainEXP(amt);
	}
	void takeDamage(welltype amt) {
		pcclass->HP->reduceCurrent(amt);
	}
	void heal(welltype amt) {
		pcclass->HP->increaseCurrent(amt);
	}


	


};