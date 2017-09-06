// 461HammingDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int HammingDistance(int x, int y) //beat 26% in all c++ submit
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
//�����Ͽ���
// beat 3% = =����û�Լ��ĺ�...��Ϊÿ�ζ�����32���жϣ�O(n)
int HammingDistance_bit(int x, int y) 
{
    int count = 0;
    int result = x ^ y;
    for(int i = 0; i < 32; ++i)
    {
        if ((result >> i) & 0x01)
            ++count;
    }
    return count;
}

int main()
{
    printf("%d", HammingDistance_bit(1, 12));
    getchar();
    return 0;
}

