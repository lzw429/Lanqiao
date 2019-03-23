//问题描述
//　　给定n个十六进制正整数，输出它们对应的八进制数。
//
//输入格式
//　　输入的第一行为一个正整数n （1<=n<=10）。
//　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。
//
//输出格式
//　　输出n行，每行为输入对应的八进制正整数。
//
//　　【注意】
//　　输入的十六进制数不会有前导0，比如012A。
//　　输出的八进制数也不能有前导0。
//
//样例输入
//　　2
//　　39
//　　123ABC
//
//样例输出
//　　71
//　　4435274
//
//　　【提示】
//　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。


// 进制转换的中间进制一般是常用的十进制，二进制的操作相对更复杂。

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int src = 16;
const int dest = 8;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        // 首先将十六进制数转换为十进制
        long long dec = 0;
        int c = 1;
        int x;
        for (int i = str.size() - 1; i >= 0; --i) {
            if ('0' <= str[i] && str[i] <= '9')
                x = str[i] - '0';
            else if ('A' <= str[i] && str[i] <= 'Z')
                x = str[i] - 'A' + 10;
            dec += x * c;
            c *= src;
        }

        // 然后将十进制数转换为八进制
        string res;
        do {
            int t = dec % dest;
            dec /= dest;

            char ch;
            if (t > 9) ch = (char) (t - 10 + 'A');
            else ch = (char) (t + '0');
            res.push_back(ch);
        } while (dec);

        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}