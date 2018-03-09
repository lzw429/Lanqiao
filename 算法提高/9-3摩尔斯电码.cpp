/*
 摩尔斯电码仅由'*'和'-'组成，可将字母看做完全二叉树上的结点
 '*'表示左子树，i=i*2
 '-'表示右子树，i=i*2+1
 没有对应字母的用数字0填充，根结点str[1]也是0，第一个字母从根结点的下一层开始
 */

#include <iostream>

using namespace std;

int main() {
    string charSet = "00etianmsurwdkgohvf0l0p0b0cyzq00";
    string code; // 输入字符串
    while (cin >> code) {
        const int size = code.size();
        int i; // charSet的索引，在树上查找字符
        int cur; // 输入字符串s的索引
        for (i = 1, cur = 0; cur < size; cur++) {
            if (code[cur] == '*')i *= 2;
            else if (code[cur] == '-')i = i * 2 + 1;
            else if (code[cur] == '|') {
                cout << charSet[i];
                i = 1;
            }
        }
        cout << charSet[i]; // s表示的最后一个字母后没有'|'
    }
    return 0;
}
