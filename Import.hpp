#ifndef IMPORT
#define IMPORT

#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>

#include "StockValue.hpp"

using namespace std;

class Import
{

public:
  Import(){};
  //vector<vector<string>> getData(string fileName, int index);
  vector<StockValue> importLastMonth(string fileName);

private:
};

#endif