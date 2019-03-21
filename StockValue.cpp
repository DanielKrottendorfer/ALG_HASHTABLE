

#include "StockValue.hpp"
#include <iostream>
#include <vector>
using namespace std;

StockValue::StockValue(vector<string> line)
{

    int y = stoi(line[0].substr(0,3));
    int m = stoi(line[0].substr(5,6));
    int d = stoi(line[0].substr(8,9));
    
    float o = stof(line[1]);
    float h = stof(line[2]);
    float l = stof(line[3]);
    float c = stof(line[4]);
    float v = stof(line[5]);
    float a = stof(line[6]);

    this->date[0] = y;
    this->date[1] = m;
    this->date[2] = d;
    this->open = o;
    this->high = h;
    this->low = l;
    this->close = c;
    this->volume = v;
    this->adj = a;

}

void StockValue::print()
{
    cout << date[0] << open << high << close;
}