#ifndef HEROES_MAGE_H
#define HEROES_MAGE_H

class Mage : public Hero
{
public:
    explicit Mage(std::string n = "Unknown");
    ~Mage() override;
    void attack(Hero &) override;
    void equip() override;
    const void showItems() const override;
};

#endif //HEROES_MAGE_H
