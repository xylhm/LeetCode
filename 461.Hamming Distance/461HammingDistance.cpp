// 461HammingDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// 题目：
/*
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 231. 
Example: 
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
 */

// 解题思路：
// 首先将两个数异或，得到这两个数不同的地方。然后计算异或得到的数中bit为1的个数就行了。
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
//从网上看的
// beat 3% = =，还没自己的好...因为每次都做了32次判断，O(n)
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

// 一个好的解法，很棒，眼前一亮。
// 每次减一时候都会借位，然后再和之前的数相与，这样被借位的那一位1就被置零了。Orz
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

