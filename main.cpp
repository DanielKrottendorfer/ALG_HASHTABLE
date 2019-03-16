
#include <iostream>
#include <math.h>
using namespace std;

#include "Stock.hpp"
#include "Hashtable.hpp"

int main()
{
    Stock s("name");
    Stock a("anme");
    Stock m("naem");
    Stock e("enam");

    Hashtable t;
    t.add(a);
    t.add(s);
    t.add(m);
    t.add(e);
    t.printTable();
    t.del("anme");
    t.printTable();
}