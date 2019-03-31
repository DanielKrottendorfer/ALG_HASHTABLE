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

    //wir erstellen eine neu HTB und öffnen ein file und überprüfen ob es geklappt hat

    Hashtable t;
    ifstream saveFile("save.txt");

    if (!saveFile.is_open())
    {
        cout << "upps da ist etwas schief gelaufen" << endl;
        return t;
    }

    string line;

    // schleife läuft so lange wei es Zeilen gibt

    while (getline(saveFile, line))
    {

        //hier wird der Index ausgelesen
        int index = stoi(line.substr(1, line.size() - 1));

        string name;
        string shortform;
        string wkn;
        string dependencies;

        //hier werden die Eigenschaften der Aktie ausgelesen
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

        
        //hier werden die Werte der Aktie ausgelesen und in einen StockValue vector geschrieben

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


            skV.push_back(n);
        }
        
        // hier wird der StockValue vector übergeben und anschließend wird die Aktie in die HTB an einem gewissen Index eingetragen

        s.setValues(skV);
        t.addAtIndex(s, index);
    }

    // das file wird geschlossen und die HTB zurückgegeben

    saveFile.close();

    return t;
}