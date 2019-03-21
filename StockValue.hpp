
#include <iostream>
class StockValue
{

  public:
    StockValue(vector<string> line);
    void print();

  private:
    int date[3];
    float open;
    float high;
    float low;
    float close;
    float volume;
    float adj;
};