#ifndef STOCK
#define STOCK

#include <iostream>
#include <math.h>
#include <vector>

#include "StockValue.hpp"
using namespace std;

/*
Die Klasse Stock stellt eine Aktie dar und hat als Eigenschaft, Name, Kurzform des Namens, WKN Nummer und die Werte die die Aktienwert.  

Weiteres besitzt die Klasse die Eigenschaft “dependencies” 
dieser int zeigt an wie viele andere Datensätze mit diesem 
Datensatz kollidiert sind was später zum Suchen von Datensätzen essenziell ist.
*/

class Stock
{

public:
  Stock(string n, string s, int w, int d) : name(n), shortform(s), wkn(w), dependencies(d){};
  Stock(){};

  int hash();

  string getName();
  string getShortform();
  void setName(string n);
  void setValues(vector<StockValue> v);
  vector<StockValue> getValues();
  void printValues();
  void printLastValue();

  void incDependencie();
  void decDependencie();
  int getDependencies();

  bool hasDependencies();

  string toString();

private:
  string name;
  string shortform;
  int wkn;
  vector<StockValue> values;

  int dependencies = 0;
};

#endif