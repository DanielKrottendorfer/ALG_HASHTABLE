
#include <iostream>
#include <math.h>

#include "Stock.hpp"
#include "Hashtable.hpp"
using namespace std;

Hashtable::Hashtable()
{
    for (int i = 0; i < capacity; i++)
    {
        tab[i].setName("");
    }
}

int Hashtable::add(Stock toAdd)
{

    /* die HTB darf nicht zu 100% befüllt werden weil 
    wir am ende eien leere Zelle brauchen
    */

    if (valueC > capacity - 1)
    {
        return -1;
    }

    // der hashvalue wird berechnet
    int hashV = toAdd.hash() % capacity;

    //es wird überprüft ob es den namen schon gibt
    if (tab[hashV].getName() == toAdd.getName())
    {
        cout << "Diese Aktie existiert bersits!" << endl;
        return -1;
    }

    if (tab[hashV].getName() == "")
    {
        tab[hashV] = toAdd;
        valueC++;
        return hashV;
    }
    else
    {
        tab[hashV].incDependencie();
    }

    /* wir gehen mit b=1 in die schleife weil wir die erste
    Position schon überprüft haben und wir uns einen unnötigen
    Schleifnezyklus spareben dann hashV + 0^2 == hashV - 0^2
    */

    int base = 1;

    for (int i = 0; base < capacity; i++)
    {
        
        /* variable i dient hier zur alternierenden quadratischen
        sondierung, wenn i gerade ist ist base^2 positivund
        wenn i ungerade ist ist base^2 negativ und base wird
        erhöht*/

        int index = 0;
        if (i % 2 == 0)
        {

            index = hashV + pow(base, 2);
            while (index >= capacity)
            {
                index -= capacity;
            }
        }
        else
        {

            index = hashV - pow(base, 2);
            while (index < 0)
            {
                index += capacity;
            }
            base++;
        }

        // check ob der name schon existiert

        if (tab[index].getName() == toAdd.getName())
        {
            cout << "Diese Aktie existiert bersits!" << endl;
            return -1;
        }

        /* wenn leer dann wird die Aktie eingefügt
         wenn kollision dann wird die dependencie um 1
         erhöht*/

        if (tab[index].getName() == "")
        {
            tab[index] = toAdd;
            valueC++;
            return index;
        }
        else
        {
            tab[index].incDependencie();
        }
    }
    return -1;
};

bool Hashtable::del(string toDel)
{
    int hashV = 1;

    //hashVale wird berechnet

    for (int i = 0; i < toDel.length(); i++)
    {
        hashV *= toDel[i];
    };

    hashV %= capacity;

    int base = 0;
    int loopC = 0;

    int index = hashV;

    // der wert wird in der HTB gesucht der index und die basis wird gespeichert
    for (int i = 0; base < capacity; i++)
    {

        if (tab[index].getName() == toDel)
        {
            loopC = i - 1;
            break;
        }
        else
        {
            if (!tab[index].hasDependencies())
            {
                cout << "not found";
                return false;
            }
        }

        if (i % 2 == 0)
        {
            index = hashV + pow(base, 2);
            while (index >= capacity)
            {
                index -= capacity;
            }
        }
        else
        {
            index = hashV - pow(base, 2);
            while (index < 0)
            {
                index += capacity;
            }
            base++;
        }
    }

    /*die dependencies der Werte mit dem der Wert
    kollidiert werden verringert
    */

    for (int i = 0, b = 0; b < base; i++)
    {
        if (i % 2 == 0)
        {
            index = hashV + pow(b, 2);
            while (index >= capacity)
            {
                index -= capacity;
            }
        }
        else
        {
            index = hashV - pow(b, 2);
            while (index < 0)
            {
                index += capacity;
            }
        }
        b++;
        tab[index].decDependencie();
    }

    /* Der zu löschende Wert wird gelöscht und die 
    verbleibenden werte werden nachgerückt*/

    int index2 = 0;

    for (int i = loopC; base < capacity; i++)
    {
        if (i % 2 == 0)
        {
            index = hashV + pow(base, 2);
            while (index >= capacity)
            {
                index -= capacity;
            }
            index2 = hashV - pow(base, 2);
            while (index2 < 0)
            {
                index2 += capacity;
            }
        }
        else
        {
            index = hashV - pow(base, 2);
            while (index < 0)
            {
                index += capacity;
            }

            index2 = hashV + pow(base + 1, 2);
            while (index2 >= capacity)
            {
                index2 -= capacity;
            }
            base++;
        }

        tab[index].setName(tab[index2].getName());
        tab[index].setValues(tab[index2].getValues());

        if (tab[index].getName() == "")
        {
            return true;
        }
    }
    return false;
};

int Hashtable::search(string toFind, bool print)
{
    /* bool print gibt an ob nach der suche der letzte
    Aktienwert ausgegeben werden soll
    der Index der gesuchten Aktie wird zurückgegeben
    falls sie gefunden wird*/
    int hashV = 1;

    for (int i = 0; i < toFind.length(); i++)
    {
        hashV *= toFind[i];
    };

    hashV %= capacity;

    int base = 0;
    int index = 0;

    for (int i = 0; base < capacity; i++)
    {
        if (i % 2 == 0)
        {

            index = hashV + pow(base, 2);
            while (index >= capacity)
            {
                index -= capacity;
            }
        }
        else
        {

            index = hashV - pow(base, 2);
            while (index < 0)
            {
                index += capacity;
            }
            base++;
        }
        if (tab[index].getName() == toFind)
        {
            if (print)
            {
                tab[index].printLastValue();
            }
            return index;
        }
        else
        {
            if (!tab[index].hasDependencies())
            {
                return -1;
            }
        }
    }

    return -1;
};

Stock *Hashtable::getStock(int i)
{
    return &tab[i];
}

void Hashtable::printTable()
{
    for (int i = 0; i < capacity; i++)
    {
        if (tab[i].getName() == "")
        {
            cout << i << " " << tab[i].getDependencies() << endl;
        }
        else
        {
            cout << tab[i].getName() << " " << tab[i].getDependencies() << endl;
        }
    }
};

void Hashtable::printStock(int i)
{
    tab[i].printValues();
}

void Hashtable::plotStock(int i)
{
    vector<StockValue> sv = tab[i].getValues();

    float min = sv[0].getAdj();
    float max = sv[0].getAdj();

    // minimum und maximum der Werte wird berechnet
    for (int i = 1; i < 30; i++)
    {
        float adj = sv[i].getAdj();

        if (adj < min)
        {
            min = adj;
        }
        if (adj > max)
        {
            max = adj;
        }
    }
    float range = max - min;

    int *d1 = sv[29].getDate();
    int *d2 = sv[0].getDate();

    //Daten zum besseren verständnis des Diagramms werden ausgegeben

    cout << "Datum " << d1[2] << "." << d1[1] << "." << d1[0] << " bis " << d2[2] << "." << d2[1] << "." << d2[0] << endl;

    cout << "Berichtigter Kurs min " << min << " max " << max << endl;

    cout << "--------------------------------" << endl;

    for (float i = 0.9; i > 0; i -= 0.1)
    {
        cout << "|";

        for (int y = 29; y >= 0; y--)
        {

            float adj = sv[y].getAdj();
            adj -= min;
            adj /= range;

            if (adj >= i && adj <= i + 0.1)
            {
                cout << 'x';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << "|";
        cout << endl;
    }

    cout << "--------------------------------" << endl;
}

Stock *Hashtable::getTable()
{
    return tab;
}

int Hashtable::size()
{
    return capacity;
}

void Hashtable::addAtIndex(Stock s, int i)
{
    tab[i] = s;
}

string Hashtable::toString()
{

    string s;

    for (int i = 0; i < capacity; i++)
    {
        if (tab[i].hasDependencies())
        {
            s += "<";
            s += to_string(i);
            s += "\n";
            s += tab[i].toString();
        }
    }

    return s;
}
