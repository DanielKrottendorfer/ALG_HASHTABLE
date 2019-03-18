
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

#include "Stock.hpp"
#include "Hashtable.hpp"
#include "Import.hpp"

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

    Import ms;
    vector<vector<string>> msDataVector;
    msDataVector = ms.getData("msft.csv");

    cout << "Datum: " << msDataVector[0][0] << endl;
    cout << "Open: " << msDataVector[1][0] << endl;
    cout << "High: " << msDataVector[2][0] << endl;
    cout << "Low: " << msDataVector[3][0] << endl;
    cout << "Close: " << msDataVector[4][0] << endl;
    cout << "Volume: " << msDataVector[5][0] << endl;
    cout << "Adj Close: " << msDataVector[6][0] << endl;
}