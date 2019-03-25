

#include "StockValue.hpp"
#include <iostream>
#include <vector>
using namespace std;

StockValue::StockValue(){};
StockValue::StockValue(int * date,float open,float high,float low,float close,int volume,float adj)
{

    this->date[0] = date[0];
    this->date[1] = date[1];
    this->date[2] = date[2];
    this->open = open;
    this->high = high;
    this->low = low;
    this->close = close;
    this->volume = volume;
    this->adj = adj;

}

void StockValue::print()
{
    cout << date[0] << " " << date[1] << " " << date[2] << " " << open << " " <<  high << " " <<  close << endl;
}