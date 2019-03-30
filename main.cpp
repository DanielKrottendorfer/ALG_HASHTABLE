
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#include "Stock.hpp"
#include "Hashtable.hpp"
#include "Import.hpp"

#include "Serialize.hpp"

int main()
{

    cout << "1.ADD:Eine Aktie mit Namen, WKNund Kürzel wird hinzugefügt." << endl;
    cout << "2.DEL: Aktie wird gelöscht." << endl;
    cout << "3.IMPORT: Kurswerte für eine Aktie werden aus einer csv Datei importiert." << endl;
    cout << "4.SEARCH: Eine Aktiewird in der Hashtabelle gesucht (Eingabe von Namen oder Kürzel) und der aktuellste Kurseintrag (Date,Open,High,Low,Close,Volume,Adj Close)wirdausgegeben." << endl;
    cout << "5.PLOT: Die Schlusskurse der letzten 30 Tage einer Aktiewerden als ASCII Grafik ausgegeben, Format ist frei wählbar." << endl;
    cout << "6.SAVE <filename>: Programm speichert die Hashtabelle in eine Datei ab." << endl;
    cout << "7.LOAD <filename>: Programm lädt die Hashtabelle aus einer Datei." << endl;
    cout << "8.QUIT: Programm wird beendet." << endl;

    int selected = -1;

    int input = 0;

    Hashtable t;

    map<string, string> dictionary;

    //dict["abc"] = "cde";

    Import csv;
    vector<vector<vector<string>>> dataVector;

    bool running = true;

    while (running)
    {
        cout << ":";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            cout << "ADD: " << endl;
            cout << "Name: ";
            string i = "";
            cin >> i;

            cout << "Shortform: ";
            string y = "";
            cin >> y;

            cout << "WKN: ";
            int wkn = 0;
            cin >> wkn;

            dictionary[y] = i;

            Stock st(i, y, wkn, 0);

            t.add(st);
        }
        break;
        case 2:
        {
            cout << "DEL: ";
            string i = "";
            cin >> i;

            if (dictionary[i].length() > 0)
            {
                i = dictionary[i];
            }

            if (t.del(i))
            {
                cout << "deleted";
            }
            else
            {
                cout << " not deleted";
            }

            cout << endl;
        }
        break;
        case 3:
        {
            cout << "IMPORT (Dateiname.csv): ";
            string i;
            cin >> i;

            cout << "Welche Aktie: ";
            string a;
            int b;
            cin >> a;
            if (dictionary[a].length() > 0)
            {
                a = dictionary[a];
            }
            b = t.search(a, false);

            if (b == -1)
            {
                cout << "Aktie nicht vorhanden!" << endl;
                break;
            }

            vector<StockValue> sv = csv.importLastMonth(i);
            t.getStock(b)->setValues(sv);

            dataVector.push_back(csv.getData(i, b)); // append new data to vector
        }
        break;
        case 4:
        {
            cout << "SEARCH: ";
            string i = "";
            cin >> i;

            if (dictionary[i].length() > 0)
            {
                i = dictionary[i];
            }

            //cout << i << " at index " << t.search(i) << endl;
            int y = t.search(i, true);
            cout << y << " index" << endl;
        }
        break;
        case 5:
        {
            /* PLOT */

            cout << "Welche Aktie: ";

            string a;
            cin >> a;
            if (dictionary[a].length() > 0)
            {
                a = dictionary[a];
            }
            int b;
            b = t.search(a, false);

            if (b == -1)
            {
                cout << "Aktie nicht vorhanden!" << endl;
                break;
            }

            t.plotStock(b);
        }
        break;
        case 6:
            /* SAVE */

            SaveHashtable(t);

            break;
        case 7:
            /* LOAD */
            {
                t = LoadHashtable();
            }
            break;
        case 8:
            running = false;
            break;
        case 9:
            t.printTable();
            break;
        case 10:
        {
            vector<StockValue> sv = csv.importLastMonth(string("msft.csv"));

            for (int i = 0; i < sv.size(); i++)
            {
                sv[i].print();
            }
        }
        break;
        default:
            break;
        }
    }
}