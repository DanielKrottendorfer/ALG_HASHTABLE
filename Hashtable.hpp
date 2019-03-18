#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <math.h>

#include "Stock.hpp"
using namespace std;


class Hashtable
{
  public:

    Hashtable(){};
    bool add(Stock toAdd);
    bool del(string toDel);
    int search(string toDel);
    void printTable();

  private:
    //capacity is gonna be 2003 in the final version
    const int capacity = 23;
    Stock tab[23];
    int valueC = 0;
    //ValueCount
};

#endif