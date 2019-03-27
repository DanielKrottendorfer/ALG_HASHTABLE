
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

    if (valueC >= capacity - 1)
    {
        return -1;
    }

    int hashV = toAdd.hash() % capacity;

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

    int base = 1;

    for (int i = 0; base < capacity; i++)
    {
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

        if (tab[index].getName() == "")
        {
            tab[index] = toAdd;
            valueC++;
            return index;
        }
        else
        {
            tab[index].incDependencie();
            cout << "inc" << endl;
        }
    }
    return -1;
};

bool Hashtable::del(string toDel)
{
    int hashV = 1;

    for (int i = 0; i < toDel.length(); i++)
    {
        hashV *= toDel[i];
    };

    hashV %= capacity;

    int base = 0;
    int loopC = 0;

    int index = hashV;
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

    //cout << " index: " << index << endl;

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

    // printTable();

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

        cout << "index1: " << index << " index2: " << index2 << endl;
        
        tab[index].setName(tab[index2].getName());
        tab[index].setValues(tab[index2].getValues());
        
        if (tab[index].getName() == "")
        {
            return true;
        }
    }
    printTable();
    cout << "end";
    return false;
};

int Hashtable::search(string toFind)
{

    if (valueC >= capacity - 1)
    {
        return -1;
    }

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

            base++;
        }
        else
        {

            index = hashV - pow(base, 2);
            while (index < 0)
            {
                index += capacity;
            }
        }


        if (tab[index].getName() == toFind)
        {
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

    cout << "min " << min << " max " << max << " range " << range << endl;

    for (float i = 0.9; i > 0; i -= 0.1)
    {
        for (int y = 0; y < 30; y++)
        {

            float adj = sv[y].getAdj();
            adj -= min;
            adj /= range;

            if (adj > i && adj < i + 0.1)
            {
                cout << 'x';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
