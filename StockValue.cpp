

#include "StockValue.hpp"
#include <iostream>
#include <vector>
using namespace std;

StockValue::StockValue(){};
StockValue::StockValue(int *date, float open, float high, float low, float close, int volume, float adj)
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
    cout << "Datum: " << date[2] << "." << date[1] << "." << date[0] << " Open: " << open << " High: " << high << " Low: " << low << " Close: " << close << " Volume: " << volume << " Adj: " << adj << endl;
}

float StockValue::getAdj()
{
    return adj;
}

int *StockValue::getDate()
{
    return date;
}

std::string StockValue::toString()
{
    std::string s;

    s += to_string(date[0]);
    s += "-";
    if (date[1] < 10)
    {
        s += "0";
    }
    s += to_string(date[1]);
    s += "-";
    if (date[2] < 10)
    {
        s += "0";
    }
    s += to_string(date[2]);
    s += ",";
    s += to_string(open);
    s += ",";
    s += to_string(high);
    s += ",";
    s += to_string(low);
    s += ",";
    s += to_string(close);
    s += ",";
    s += to_string(volume);
    s += ",";
    s += to_string(adj);
    s += "\n";

    return s;
}