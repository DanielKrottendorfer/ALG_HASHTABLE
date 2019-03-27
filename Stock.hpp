#ifndef STOCK
#define STOCK

#include <iostream>
#include <math.h>
#include <vector>

#include "StockValue.hpp"
using namespace std;

class Stock
{

  public:
    Stock(string n) : name(n){};
    Stock(){};

    int hash();

    string getName();
    void setName(string n);
    void setValues(vector<StockValue> v);
    vector<StockValue> getValues();
    void printValues();

    void incDependencie();
    void decDependencie();
    int getDependencies();

    bool hasDependencies();

  private:
    string name;
    vector<StockValue> values;

    int dependencies = 0;
};

#endif