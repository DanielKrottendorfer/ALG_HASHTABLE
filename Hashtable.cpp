
#include <iostream>
#include <math.h>

#include "Stock.hpp"
#include "Hashtable.hpp"
using namespace std;

int Hashtable::add(Stock toAdd)
{

    if (valueC >= capacity - 1)
    {
        return -1;
    }

    int hashV = toAdd.hash() % capacity;

    int base = 0;

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
        if (tab[index].getName() == "")
        {
            tab[index] = toAdd;
            return index;
        }
    }

    return -1;
};

bool Hashtable::del(string toDel)
{
    if (valueC >= capacity - 1)
    {
        return -1;
    }

    int hashV = 1;

    for (int i = 0; i < toDel.length(); i++)
    {
        hashV *= toDel[i];
    };

    hashV %= capacity;

    int base = 0;
    int index = 0;

    bool found = false;

    for (int i = 0; base < capacity; i++)
    {
        if ((i % 2) == 0)
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

        if (tab[index].getName() == toDel)
        {
            found = true;
        }
        else
        {
            if (tab[index].getName() == "")
            {
                return false;
            }
        }

        if (found)
        {
            int index2 = 0;
            if ((i % 2) == 0)
            {
                index2 = hashV - pow(base, 2);
                while (index2 < 0)
                {
                    index2 += capacity;
                }
            }
            else
            {
                index2 = hashV + pow(base + 1, 2);
                while (index2 >= capacity)
                {
                    index2 -= capacity;
                }
                base++;
            }

            tab[index].setName(tab[index2].getName());
            //cout << "index: " << index << " index2: " << index2 << endl;

        }
    }
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
            if (tab[index].getName() == "")
            {
                return -1;
            }
        }
    }

    return -1;
};

void Hashtable::printTable()
{
    for (int i = 0; i < capacity; i++)
    {
        if (tab[i].getName() == "")
        {
            cout << i << endl;
        }
        else
        {
            cout << tab[i].getName() << endl;
        }
    }
};
