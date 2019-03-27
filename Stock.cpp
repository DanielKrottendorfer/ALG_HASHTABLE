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
void Stock::setName(string n)
{
    name = n;
}

void Stock::printValues()
{
    for( int i=0 ; i<values.size() ; i++ )
    {
        values[i].print();
    }
}

void Stock::setValues(vector<StockValue> v)
{
    values = v;
}
vector<StockValue> Stock::getValues(){
    return values;
}

void Stock::incDependencie(){ dependencies++; }
void Stock::decDependencie(){ dependencies--; }
bool Stock::hasDependencies()
{
    if(dependencies>0)
    {
        return true;
    }else
    {
        return false;
    }
}

int Stock::getDependencies(){ return dependencies; }