#ifndef DISPENSER_H
#define DISPENSER_H


class Dispenser
{
    int drink;  // 1 - ������ �������, 2 - ������
    float x, y;
public:
    Dispenser();
    void pourDrink(int drink);
    void setCoords(float, float);
    std::pair<float, float> getCoords();
    void setDrink(int _drink) {drink = _drink;}
    int getDrink() {return drink;}
};

#endif // DISPENSER_H
