#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        str[i] ^= (1 << 5); // 大小写转换
    }
    cout << str;
    return 0;
}