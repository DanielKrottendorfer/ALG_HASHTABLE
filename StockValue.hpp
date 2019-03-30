#ifndef STOCKVALUE
#define STOCKVALUE

#include <iostream>


// StockValue stellt die Daten einer Aktie zu einem gewissen Zeitpunkt da

class StockValue
{

public:
  StockValue();
  StockValue(int *date, float open, float high, float low, float close, int volume, float adj);
  void print();
  int *getDate();
  float getAdj();

  std::string toString();

private:
  int date[3];
  float open;
  float high;
  float low;
  float close;
  int volume;
  float adj;
};

#endif