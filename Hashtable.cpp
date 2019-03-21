
#include <iostream>
#include <math.h>

#include "Stock.hpp"
#include "Hashtable.hpp"
using namespace std;

int Hashtable::add(Stock toAdd)
{

    if (valueC == capacity-1)
    {
        return -1;
    }

    int hashV = toAdd.hash();
    for (int b = 0; b < capacity; b++)
    {
        int index;

        index = (hashV + (int)pow(b, 2)) % capacity;
        
        if (tab[index].getName() == "")
        {
            tab[index] = toAdd;
            valueC++;
            return index;
        }


        index = (hashV - ((int)pow(b, 2))) % capacity;
        while(index<0)
        {
            index+=capacity;
        }
        
        if (tab[index].getName() == "")
        {
            tab[index] = toAdd;
            valueC++;
            return index;
        }
        
        cout << index << endl;
    }
    return -1;
};

bool Hashtable::del(string toDel)
{
    
};

int Hashtable::search(string toFind)
{
    int hashV = 1;

    for (int i = 0; i < toFind.length(); i++)
    {
        hashV *= toFind[i];
    };
    
    for (int b = 0; b < capacity; b++)
    {
        int index;
        index = hashV + (int)pow(b, 2) % capacity;

        if(tab[index].getName() == toFind)
        {
            return index;
        };

        if(tab[index].getName() == "")
        {
            return -1;
        };

        index = (hashV - ((int)pow(b, 2))) % capacity;
        while(index<0)
        {
            index+=capacity;
        }
        
        if(tab[index].getName() == toFind)
        {
            return index;
        };

        if(tab[index].getName() == "")
        {
            return -1;
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
