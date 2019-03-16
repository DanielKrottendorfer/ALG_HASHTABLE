#ifndef STOCK
#define STOCK

#include <iostream>
#include <math.h>
using namespace std;

class Stock
{

  public:
    Stock(string n) : name(n){};
    Stock(){};

    int hash();

    string getName();

  private:
    string name;
};

#endif