
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Stock.hpp"
#include "Hashtable.hpp"
#include "Import.hpp"

int main()
{

    cout << "1.ADD:Eine Aktie mit Namen, WKNund Kürzel wird hinzugefügt.\n2.DEL: Aktie wird gelöscht.\n3.IMPORT: Kurswerte für eine Aktie werden aus einer csv Datei importiert.\n4.SEARCH: Eine Aktiewird in der Hashtabelle gesucht (Eingabe von Namen oder Kürzel) und der aktuellste Kurseintrag (Date,Open,High,Low,Close,Volume,Adj Close)wirdausgegeben.\n5.PLOT: Die Schlusskurse der letzten 30 Tage einer Aktiewerden als ASCII Grafik ausgegeben, Format ist frei wählbar.\n6.SAVE <filename>: Programm speichert die Hashtabelle in eine Datei ab.\n7.LOAD <filename>: Programm lädt die Hashtabelle aus einer Datei.\n8.QUIT: Programm wird beendet.\n"
         << endl;

    int selected = -1;

    int input = 0;

    Hashtable t;

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
            cout << "ADD: ";
            string i = "";
            cin >> i;
            t.add(i);
        }
        break;
        case 2:
        {
            cout << "DEL: ";
            string i = "";
            cin >> i;
            t.del(i);
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
            b = t.search(a);

            if (b == -1)
            {
                cout << "Aktie nicht vorhanden!" << endl;
                break;
            }

            dataVector.push_back(csv.getData(i, b)); // append new data to vector
        }
        break;
        case 4:
        {
            cout << "SEARCH: ";
            string i = "";
            cin >> i;
            t.search(i);
        }
        break;
        case 5:
        {
            /* PLOT */
            cout << "Anzahl an csv Daten: " << dataVector.size() << endl;

            for (int i = 0; i < dataVector.size(); i++)
            {
                cout << "Datum von Index nummer " << dataVector[i][7][0] << ": " << dataVector[i][0][0] << endl;
            }
        }
        break;
        case 6:
            /* SAVE */
            break;
        case 7:
            /* LOAD */
            break;
        case 8:
            running = false;
            break;
        case 9:
            t.printTable();
            break;

        default:
            break;
        }
    }

    /*
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
    */
}