#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <math.h>

#include "Stock.hpp"
using namespace std;

/* die Klasse Hashtable ist eine ... Hashtable
capacity gibt die gröze det HTB an
tab ist das array mit den Werten
valueC gibt an wie viele Datensätze in der HTB sind
*/

class Hashtable
{
public:
  Hashtable();
  int add(Stock toAdd);
  bool del(string toDel);
  int search(string toDel, bool print);
  void printTable();
  void printStock(int i);
  void plotStock(int i);
  Stock *getStock(int i);
  Stock *getTable();

  void addAtIndex(Stock s, int i);

  int size();
  string toString();

private:
  int capacity = 1511;
  Stock tab[1511];
  int valueC = 0;
};

#endif