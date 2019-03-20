#ifndef IMPORT
#define IMPORT

#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

class Import
{

public:
  Import(){};
  vector<vector<string>> getData(string fileName);

private:
  vector<vector<string>> dataVector;
};

#endif