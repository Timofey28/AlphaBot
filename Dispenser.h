#ifndef DISPENSER_H
#define DISPENSER_H


class Dispenser
{
    int drink;  // 1 - первый напиток, 2 - второй
    float x, y;
public:
    Dispenser();
    void pourDrink(int drink);
    void setCoords(float _x, float _y) {x = _x; y = _y;}
    std::pair<float, float> getCoords();
    void setDrink(int _drink) {drink = _drink;}
    int getDrink() {return drink;}
};

#endif // DISPENSER_H
