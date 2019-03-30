#include <iostream>
#include <math.h>

#include "Stock.hpp"
using namespace std;


// multiplizeirt alle Chars des Namens auf um einen hashwert zu erzeugen

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

//gibt alle Aktienwerte aus
void Stock::printValues()
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i].print();
    }
}


// gibt den aktuellsten Aktiebwert aus
void Stock::printLastValue()
{
    if (values.size() > 0)
    {
        values[0].print();
    }
}

void Stock::setValues(vector<StockValue> v)
{
    values = v;
}
vector<StockValue> Stock::getValues()
{
    return values;
}

// erhöhen / verringern der dependencies

void Stock::incDependencie() { dependencies++; }
void Stock::decDependencie() { dependencies--; }

// gibt an ob der Datensatz dependencies hat
bool Stock::hasDependencies()
{
    if (dependencies > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stock::getDependencies() { return dependencies; }

//ToString wandelt alle Eigenschaften und Aktien Daten in einen String um. 

string Stock::toString()
{

    string s;

    s += name;
    s += ",";
    s += shortform;
    s += ",";
    s += to_string(wkn);
    s += ",";
    s += to_string(dependencies);

    s += "\n";

    for (int i = 0; i < values.size(); i++)
    {
        s += values[i].toString();
    }
    return s;
}