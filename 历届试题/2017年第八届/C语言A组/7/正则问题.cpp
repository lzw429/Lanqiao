//
// Created by syh on 19-3-18.
//

#include <iostream>
#include <cstring>

using namespace std;

char str[100];
int len;
int i = 0;

/**
 * 对括号内表达式进行计算
 * 该函数是递归的，每一次递归处理一对括号
 */
int par() {
    int preNum = 0; // 记忆'|'之前的x的最大数量
    int curNum = 0; // 保存连续的x的数量
    while (i < len) { // 注意不要尝试将 i++ 写在四个条件语句之外，这将破坏递归结构
        if (str[i] == 'x') {
            i++;
            curNum++;
        } else if (str[i] == '(') {
            i++;
            curNum += par();
        } else if (str[i] == ')') {
            i++;
            preNum = max(preNum, curNum);
            return preNum;
        } else if (str[i] == '|') {
            i++;
            preNum = max(preNum, curNum);
            curNum = 0;
        }
    }
    preNum = max(preNum, curNum);
    return preNum;
}

int main() {
    cin >> str;
    len = strlen(str);
    int ans = par();
    cout << ans << endl;
    return 0;
}