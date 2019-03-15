//
// Created by syh on 19-3-15.
//

// 补充的字符数量 = 原字符串长度 - 原字符串与其翻转字符串的最长公共子序列的长度

#include <iostream>
#include <algorithm>

using namespace std;

string str;
string rev;
const int maxn = 1000;
int dp[maxn][maxn]; // dp[i][j] 是字符串a前i位和字符串b前j位的最长公共子序列的长度
/**
 *
 * @param a 字符串
 * @param b 字符串
 * @return 最长公共子序列长度
 */
int lcs(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[i]) {

            } else {

            }
        }
    }
}

int main() {
    cin >> str;
    rev = reverse(str.begin(), str.end());
    return 0;
}