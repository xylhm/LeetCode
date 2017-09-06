// 461HammingDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int HammingDistance(int x, int y)
{
    int result = x ^ y;
    int count = 0;
    while (result / 2)
    {
        if(result % 2)
        {
            ++count;
        }
        result = result / 2;
    }
    if (result % 2)
        ++count;
    return count;
}

int main()
{
    printf("%d", HammingDistance(1, 12));
    getchar();
    return 0;
}

