#include "Dispenser.h"


Dispenser::Dispenser()
{
    printf("\nСоздан объект дозатора");
}

void Dispenser::pourDrink(int drink)
{
    printf("\nНалит напиток №%d", drink);
}

std::pair<float, float> Dispenser::getCoords()
{
    return (std::pair<float, float>) {x, y};
}
