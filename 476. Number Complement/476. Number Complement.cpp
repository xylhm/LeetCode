// 476. Number Complement.cpp : Defines the entry point for the console application.
//
/*

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/
#include "stdafx.h"

int findComplement(int num) {
	int offset = 0;
	int temp = num;
	do {
		++offset;
		temp = temp >> 1;
	} while (temp != 0);
	//++offset;
	num = ~num;
	num = num << 32 - offset;
	num = num >> 32 - offset;
	return num;
}

int main()
{
	int n = findComplement(5);
    return 0;
}

