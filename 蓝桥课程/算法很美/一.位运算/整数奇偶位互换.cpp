//
// Created by syh on 19-3-19.
//


/*
 * 与运算：1保留，0消除
 */
#include <iostream>

using namespace std;

int exchangeOddEven(int x) {
    int odd = (x & 0xaaaaaaaa); // 1010 1010 1010 1010 1010 1010 1010 1010
    int even = (x & 0x55555555); // 0101 0101 0101 0101 0101 0101 0101 0101
    return (odd >> 1) + (even << 1);
}

int main() {
    int x;
    cin >> x;
    cout << exchangeOddEven(x) << endl;
}