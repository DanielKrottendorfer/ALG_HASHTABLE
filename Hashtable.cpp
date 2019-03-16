
#include <iostream>
#include <math.h>

#include "Stock.hpp"
#include "Hashtable.hpp"
using namespace std;

bool Hashtable::add(Stock toAdd)
{

    if (valueC == capacity)
    {
        return false;
    }

    int index = toAdd.hash();

    for (int b = 0; (int)pow(b, 2) < capacity; b++)
    {
        index = abs(index + (int)pow(b, 2)) % capacity;
        if (tab[index].getName() == "")
        {
            tab[index] = toAdd;
            valueC++;
            return true;
        }
    }
    return false;
};

bool Hashtable::del(string toDel)
{

    int index = 1;

    for (int i = 0; i < toDel.length(); i++)
    {
        index *= toDel[i];
    };

    int matchB = -1;
    int matchI = -1;

    for (int b = 0; (int)pow(b, 2) < capacity; b++)
    {
        index = abs(index + (int)pow(b, 2)) % capacity;

        if (matchB < 0 && tab[index].getName() == toDel)
        {
            matchB = b;
            matchI = index;
        }

        if (tab[index].getName() == "" && matchB >= 0)
        {
            while (tab[matchI].getName() != "")
            {
                int nextI = abs((matchI + (int)pow(matchB, 2))) % capacity;

                tab[matchI] = tab[nextI];
                matchI = nextI;
                matchB++;
            }
            valueC--;
            return true;
        }
        else
        {
            if (tab[index].getName() == "" && matchB < 0)
            {
                return false;
            }
        }
    }
    return false;
};

Stock *Hashtable::search(string toDel)
{
    return nullptr;
};

void Hashtable::printTable()
{
    for (int i = 0; i < capacity; i++)
    {
        if (tab[i].getName() == "")
            cout << i << endl;
        else
            cout << tab[i].getName() << endl;
    }
};
