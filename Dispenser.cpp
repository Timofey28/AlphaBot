#include "Dispenser.h"
#include <bits/stdc++.h>

Dispenser::Dispenser()
{
    printf("\n������ ������ ��������");
}

void Dispenser::pourDrink(int drink)
{
    printf("\n����� ������� �%d", drink);
}

void Dispenser::setCoords(float _x, float _y)
{
    x = _x;
    y = _y;
}

std::pair<float, float> Dispenser::getCoords()
{
    return (std::pair<float, float>) {x, y};
}
