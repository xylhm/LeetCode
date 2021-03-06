// 657. Judge Route Circle.cpp : Defines the entry point for the console application.
//
/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
Example 1:
Input: "UD"
Output: true

Example 2:
Input: "LL"
Output: false

*/
#include "stdafx.h"
#include "string"
#include "algorithm"
using namespace std;
bool judgeCircle(string moves) {
    unsigned int x = 0;
    unsigned int y = 0;
    for (auto i : moves) {
        switch (i) {
        case 'D':
            y -= 1;
            break;
        case 'U':
            y += 1;
            break;
        case 'L':
            x -= 1;
            break;
        case 'R':
            x += 1;
            break;
        }
    }
    if (x == 0 && y == 0)
        return true;
    return false;
}
int main()
{
    string s("UD");
    judgeCircle(s);
    return 0;
}

