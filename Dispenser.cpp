#include "Dispenser.h"


Dispenser::Dispenser()
{
    printf("\n������ ������ ��������");
}

void Dispenser::pourDrink(int drink)
{
    printf("\n����� ������� �%d", drink);
}

std::pair<float, float> Dispenser::getCoords()
{
    return (std::pair<float, float>) {x, y};
}
