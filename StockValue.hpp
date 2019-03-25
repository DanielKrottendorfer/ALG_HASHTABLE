#ifndef STOCKVALUE
#define STOCKVALUE

#include <iostream>
class StockValue
{

  public:
    StockValue();
    StockValue(int * date,float open,float high,float low,float close,int volume,float adj);
    void print();

    float getAdj();

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