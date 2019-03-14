#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <vector>

class Hashtable
{

  struct stock {
    std::string name;
    //Wertpapierkennnummer
    std::string wkn;
    //Kursdaten
    std::vector<std::string> kd;
  };

  private:
    const int size = 1559;
    stock values[1559];

  public:
    void addValue(std::string name,std::string wkn);
    void printTable();
};

#endif