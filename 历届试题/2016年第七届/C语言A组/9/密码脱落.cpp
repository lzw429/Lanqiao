//
// Created by syh on 19-3-15.
//

/*
例如，输入：
ABCBA
则程序应该输出：
0

再例如，输入：
ABDCDCBABC
则程序应该输出：
3
 */

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
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[a.size()][b.size()];
}

int main() {
    int ans;
    cin >> str;
    string rev(str);
    reverse(rev.begin(), rev.end());
    int l = lcs(str, rev);

    ans = str.size() - l;
    cout << ans << endl;
    return 0;
}
