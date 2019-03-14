//
// Created by syh on 19-3-14.
//

#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i <= 100; i++) { // 假设从第i岁开始过生日
        for (int j = i; j <= 100; j++) { // 假设今年j岁
            int t = (i + j) * (j - i + 1) / 2; // 等差数列求和
            if (t == 236)
                cout << i << " " << j << endl;
        }
    }
    return 0;
}