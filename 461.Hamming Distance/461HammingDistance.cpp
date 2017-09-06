// 461HammingDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// ��Ŀ��
/*
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 �� x, y < 231. 
Example: 
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ��   ��

The above arrows point to positions where the corresponding bits are different.
 */

// ����˼·��
// ���Ƚ���������򣬵õ�����������ͬ�ĵط���Ȼ��������õ�������bitΪ1�ĸ��������ˡ�
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

// һ���õĽⷨ���ܰ�����ǰһ����
// ÿ�μ�һʱ�򶼻��λ��Ȼ���ٺ�֮ǰ�������룬��������λ����һλ1�ͱ������ˡ�Orz
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};

int main()
{
    printf("%d", HammingDistance_bit(1, 12));
    getchar();
    return 0;
}

