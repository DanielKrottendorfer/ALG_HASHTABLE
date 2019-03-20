
#include <iostream>
#include <math.h>

#include "Stock.hpp"
#include "Hashtable.hpp"
using namespace std;

int Hashtable::add(Stock toAdd)
{

    if (valueC == capacity-1)
    {
        return false;
    }

    int index = toAdd.hash();

    for (int b = 0; b < capacity; b++)
    {
        index = abs(index + (int)pow(b, 2)) % capacity;
        if (tab[index].getName() == "")
        {
            tab[index] = toAdd;
            valueC++;
            return index;
        }
    }
    return -1;
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

    for (int b = 0; b < capacity; b++)
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

int Hashtable::search(string toFind)
{
    int index = 1;

    for (int i = 0; i < toFind.length(); i++)
    {
        index *= toFind[i];
    };
    
    for (int b = 0; b < capacity; b++)
    {
        index = abs(index + (int)pow(b, 2)) % capacity;
        if(tab[index].getName() == toFind)
        {
            return index;
        };
    };
    return -1;
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
