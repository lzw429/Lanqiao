//
// Created by syh on 19-3-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int len;

void f(int level, vector<int> square) {
    if (level == 10) {
        len++;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        vector<int>::iterator it = find(square.begin(), square.end(), i);
        if (it != square.end()) continue; // 该数字已经出现
        switch (level) {
            case 1:
                if (abs(i - square[0]) == 1)
                    continue;
                break;
            case 2:
                if (abs(i - square[1]) == 1)
                    continue;
                break;
            case 3:
                if (abs(i - square[0]) == 1)
                    continue;
                break;
            case 4:
                if (abs(i - square[0]) == 1 || abs(i - square[3]) == 1 || abs(i - square[1]) == 1)
                    continue;
                break;
            case 5:
                if (abs(i - square[1]) == 1 || abs(i - square[4]) == 1 || abs(i - square[0]) == 1 ||
                    abs(i - square[2]) == 1)
                    continue;
                break;
            case 6:
                if (abs(i - square[2]) == 1 || abs(i - square[5]) == 1 || abs(i - square[1]) == 1)
                    continue;
                break;
            case 7:
                if (abs(i - square[3]) == 1 || abs(i - square[4]) == 1)
                    continue;
                break;
            case 8:
                if (abs(i - square[4]) == 1 || abs(i - square[5]) == 1 || abs(i - square[7]) == 1 ||
                    abs(i - square[3]) == 1)
                    continue;
                break;
            case 9:
                if (abs(i - square[5]) == 1 || abs(i - square[8]) == 1 || abs(i - square[4]) == 1 ||
                    abs(i - square[6]) == 1)
                    continue;
                break;
        }

        square.push_back(i);
        f(level + 1, square);
        square.erase(square.end() - 1); // 去掉末尾
    }
}

int main() {
    vector<int> square;
    f(0, square);
    cout << len << endl;
    return 0;
}