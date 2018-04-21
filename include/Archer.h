#ifndef HEROES_ARCHER_H
#define HEROES_ARCHER_H

class Archer :public Hero
{
public:
    explicit Archer(std::string n = "Unknown");
    ~Archer() override;
    void attack(Hero &) override;

};

#endif //HEROES_ARCHER_H
