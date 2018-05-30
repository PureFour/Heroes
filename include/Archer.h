#ifndef HEROES_ARCHER_H
#define HEROES_ARCHER_H

class Archer :public Hero
{
public:
    explicit Archer(std::string n = "Unknown");
    ~Archer() override;
    void attack(Hero &) override;
    void equip(Item&) override;
    const void showItems() const override;
};

#endif //HEROES_ARCHER_H
