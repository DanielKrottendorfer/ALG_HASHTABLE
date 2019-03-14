#include "Hashtable.hpp"

void Hashtable::addValue(std::string name,std::string wkn)
{
    int key = 1;
    for (std::string::iterator it = wkn.begin(); it != wkn.end(); ++it)
        key*= (*it-96);

    std::cout << key << std::endl;
}

void Hashtable::printTable()
{
    for(int i=0 ; i<size ; i++)
    {
        std::cout << values[i].wkn << std::endl;
    }
}
