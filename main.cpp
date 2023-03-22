#include <iostream>
#include "System.h"
#include "System.cpp"
using namespace std;


int main()
{
    setlocale(0, "");
    System system;

    while(1)
        system.processEvent();

    return 0;
}
