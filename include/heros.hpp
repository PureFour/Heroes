#include <string>

class Hero {

    private:
        int _hp;
        int _attackPoints;
        int _deffencePoints;

    public:
        Hero(int hp, int attackPoints, int deffencePoints) 
        : _hp(hp), _attackPoints(attackPoints), _deffencePoints(deffencePoints) {};

        int getHp() {return _hp;};
        int getAttackPoints() {return _attackPoints;};
        int getDeffencePoints() {return _deffencePoints;};
};

class Fight {

    //interfejs walki

    void attack(Fight &attackedHero, int _attackPoints);
    void beingAttacked(int hitPoint);

};

class Warrior : public Hero, public Fight {

    public:
        Warrior(int hp = 150, int attackPoints = 3, int deffencePoints = 3) : Hero(hp, attackPoints, deffencePoints) {};

};