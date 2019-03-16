#include <iostream>
#include <math.h>

#include "Stock.hpp"
using namespace std;

int Stock::hash()
{

    int key = 1;

    for (int i = 0; i < name.length(); i++)
    {
        key *= name[i];
    };

    return key;
}

string Stock::getName()
{
    return name;
}
