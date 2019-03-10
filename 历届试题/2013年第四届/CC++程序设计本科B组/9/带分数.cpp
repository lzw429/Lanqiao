/*

标题：带分数

    100 可以表示为带分数的形式：100 = 3 + 69258 / 714

    还可以表示为：100 = 82 + 3546 / 197

    注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

    类似这样的带分数，100 有 11 种表示法。

题目要求：
从标准输入读入一个正整数N (N<1000*1000)
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
注意：不要求输出每个表示，只统计有多少表示法！


例如：
用户输入：
100
程序输出：
11

再例如：
用户输入：
105
程序输出：
6


资源约定：
峰值内存消耗 < 64M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


  
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>

using namespace std;

const int nums_size = 9;
int nLen;

int strToInt(string str) {
    int res;
    stringstream ss;
    ss << str;
    ss >> res;
    return res;
}

char* intToStr(int num) {
    char str[9] = {};
    sprintf(str, "%d", num);
    return str;
}

bool check(const string &nums, int sum) {
    for (int i = 1; i <= nLen; i++) {
        for (int j = (nums_size - i) / 2; j <= nums_size - i - 1; j++) {
            int a = strToInt(nums.substr(0, i));
            int b = strToInt(nums.substr(i, j));
            int c = strToInt(nums.substr(i + j, nums_size - i - j));
            if (a >= sum) 
                return false;
            if(b % c == 0 && sum * c == a * c + b) {
                cout << a <<" "<< b<< " " << c << " " << endl;
                return true;                
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    nLen = intToStr(n).size();
    int cnt = 0;
    string nums = "123456789"; 
    do {
        if (check(nums, n)== true) {
            cnt++;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << cnt << endl;
    return 0;
}
