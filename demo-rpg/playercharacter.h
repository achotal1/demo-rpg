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
increaseStats(BASESTR, BASEINT);\
}

#define LEVELUP void LevelUp() override {\
welltype hp = HP->getMax() + (welltype)(BASEHP / 2.f);\
HP->setMax(hp);\
HP->increaseCurrent((welltype)(BASEHP / 2.f));\
increaseStats((stattype)((BASESTR + 1u) / 2.f), (stattype)((BASEINT + 1u) / 2.f));\
}

// CLERIC CLASS
class Cleric : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)14u;
	static const stattype BASESTR = (stattype)2u;
	static const stattype BASEINT = (stattype)3u;

	Cleric() PCCONSTRUCT
	std::string getClassName() override {
		return std::string("Cleric");

	}


private:
	LEVELUP
};

// ROGUE CLASS
class Rogue : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)12u;
	static const stattype BASESTR = (stattype)3u;
	static const stattype BASEINT = (stattype)2u;

	Rogue() PCCONSTRUCT
	std::string getClassName() override {
		return std::string("Rogue");

	}


private:
	LEVELUP;

};

// WIZARD CLASS
class Wizard : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)10u;
	static const stattype BASESTR = (stattype)1u;
	static const stattype BASEINT = (stattype)4u;

	Wizard() PCCONSTRUCT
	std::string getClassName() override {
		return std::string("Wizard");

	}


private:
	LEVELUP;

};

// WARRIOR CLASS
class Warrior : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)18u;
	static const stattype BASESTR = (stattype)4u;
	static const stattype BASEINT = (stattype)1u;

	Warrior() PCCONSTRUCT
	std::string getClassName() override {
		return std::string("Warrior");

	}

private:
	LEVELUP;

};



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
	leveltype getLevel() {
		return pcclass->getLevel();
	}
	leveltype getCurrentEXP() {
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