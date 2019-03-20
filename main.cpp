
#include <iostream>
#include <math.h>
using namespace std;

#include "Stock.hpp"
#include "Hashtable.hpp"

int main()
{

    cout << "1.ADD:Eine Aktie mit Namen, WKNund Kürzel wird hinzugefügt.\n2.DEL: Aktie wird gelöscht.\n3.IMPORT: Kurswerte für eine Aktie werden aus einer csv Datei importiert.\n4.SEARCH: Eine Aktiewird in der Hashtabelle gesucht (Eingabe von Namen oder Kürzel) und der aktuellste Kurseintrag (Date,Open,High,Low,Close,Volume,Adj Close)wirdausgegeben.\n5.PLOT: Die Schlusskurse der letzten 30 Tage einer Aktiewerden als ASCII Grafik ausgegeben, Format ist frei wählbar.\n6.SAVE <filename>: Programm speichert die Hashtabelle in eine Datei ab.\n7.LOAD <filename>: Programm lädt die Hashtabelle aus einer Datei.\n8.QUIT: Programm wird beendet.\n"
         << endl;

    int selected = -1;

    int input = 0;

    Hashtable t;

    bool running = true;

    while (running)
    {
        cout << ":" ;
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
            /* IMPORT */
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
            /* PLOT */
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