// 557. Reverse Words in a String III.cpp : Defines the entry point for the console application.
//
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
#include "stdafx.h"
#include "string"
#include "algorithm"
using namespace std;

string reverseWords1(string s) {
	string temp(s);
	size_t pos1 = 0;
	auto pos = s.find(' ');
	if (pos == string::npos) {
		reverse(s.begin(), s.end());
		return s;
	}

	do {
		pos = s.find(' ');
		reverse(temp.begin()+pos1, temp.begin() + pos);
		pos1 = pos + 1;
		s[pos] = '/';
	} while (s.find(' ') != string::npos);
	reverse(temp.begin() + pos1, temp.end());
	return temp;
}


string reverseWords(string s) {
	int n = s.size();
	int space_pos = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == ' ' || i == n - 1) {
			if (i == n - 1)
				++i;
			int start = space_pos + 1;
			int end = i - 1;
			while (start < end) {
				swap(s[start++], s[end--]);
			}
			space_pos = i;
		}
	}
	return s;
}

int main()
{
	reverseWords("Let's take LeetCode contest");
    return 0;
}

