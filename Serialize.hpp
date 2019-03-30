#include "Hashtable.hpp"
#include "StockValue.hpp"
#include "Stock.hpp"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void SaveHashtable(Hashtable t)
{

    ofstream saveFile("save.txt");

    if (!saveFile.is_open())
    {
        cout << "upps da ist etwas schief gelaufen" << endl;
        return;
    }

    saveFile << t.toString();

    saveFile.close();
}

Hashtable LoadHashtable()
{

    Hashtable t;
    ifstream saveFile("save.txt");

    if (!saveFile.is_open())
    {
        cout << "upps da ist etwas schief gelaufen" << endl;
        return t;
    }

    string line;

    while (getline(saveFile, line))
    {
        int index = stoi(line.substr(1, line.size() - 1));

        string name;
        string shortform;
        string wkn;
        string dependencies;

        getline(saveFile, name, ',');
        getline(saveFile, shortform, ',');
        getline(saveFile, wkn, ',');
        getline(saveFile, dependencies, '\n');

        Stock s(name, shortform, stoi(wkn), stoi(dependencies));

        string date;
        string open;
        string high;
        string low;
        string close;
        string volume;
        string adj;

        int d[3];
        float o;
        float h;
        float l;
        float c;
        int v;
        float a;

        vector<StockValue> skV;
        for (int i = 0; i < 30; i++)
        {
            getline(saveFile, date, ',');   // datum
            getline(saveFile, open, ',');   // open
            getline(saveFile, high, ',');   // high
            getline(saveFile, low, ',');    // low
            getline(saveFile, close, ',');  // close
            getline(saveFile, volume, ','); // volume
            getline(saveFile, adj, '\n');   // adj

            d[0] = stoi(date.substr(0, 4));
            d[1] = stoi(date.substr(5, 2));
            d[2] = stoi(date.substr(8, 2));

            v = stoi(volume);

            o = stof(open);
            h = stof(high);
            l = stof(low);
            c = stof(close);
            a = stof(adj);

            StockValue n;
            n = StockValue(d, o, h, l, c, v, a);

            cout << n.toString() << endl;

            skV.push_back(n);
        }

        s.setValues(skV);
        t.addAtIndex(s, index);
    }
    saveFile.close();

    return t;
}