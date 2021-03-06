// 728. Self Dividing Numbers.cpp : Defines the entry point for the console application.
//
/*
A self-dividing number is a number that is divisible by every digit it contains.
For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
Also, a self-dividing number is not allowed to contain the digit zero.
Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
Example 1:
Input:
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

Note:
The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

/*
解题思路：
求出num的每一位的数并令其为除数进行运算。
*/
#include "stdafx.h"
#include "vector"
#include "iostream"

using namespace std;
vector<int> selfDividedNum(int left, int right);
int main()
{
    vector<int> vec_ = selfDividedNum(1, 2200025);
	for (auto i : vec_) {
		cout << i << '\t';
	}
	cout << endl;
	getchar();
	return 0;
}

vector<int> selfDividedNum(int left, int right)
{
    vector<int> vec;
    int yushu = 0;
    for (int i = 0; i < right - left + 1; ++i) {
        int num = left + i;
        int temp = num;
        bool flag = true;
        while (temp != 0 || temp / 10 != 0)
        {
            yushu = temp % 10;
            if (yushu == 0 || num % yushu != 0) {
                flag = false;
                break;
            }
            temp /= 10;
        }
        if(flag)
            vec.push_back(left + i);
    }
    return vec;
}
