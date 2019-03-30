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
  Stock(string n, string s, int w, int d) : name(n), shortform(s), wkn(w), dependencies(d){};
  Stock(){};

  int hash();

  string getName();
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