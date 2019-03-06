
#include <iostream>

int main()
{

    int htab[13]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int inputs[6] = {41025703, 41025717, 11025749, 41025773, 31024430, 41025782};

    for (int i = 0; i < 6; i++)
    {
        int index = inputs[i]%100;
        for (int b = 0; true; b++)
        {
            index = (index + (b ^ 2)) % 13;
            if (htab[index] == 0)
            {
                htab[index] = inputs[i];
                break;
            }
        }
    }

    for (int i = 0; i < 13; i++)
    {
        std::cout << htab[i] << std::endl;
    }
    std::cout<<std::endl;
}