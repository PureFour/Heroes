#ifndef HEROES_WARRIOR_H
#define HEROES_WARRIOR_H

class Warrior : public Hero
{
public:
    explicit Warrior(std::string name = "Unknown");
    ~Warrior() override;
    void attack(Hero &) override;

};

#endif //HEROES_WARRIOR_H
