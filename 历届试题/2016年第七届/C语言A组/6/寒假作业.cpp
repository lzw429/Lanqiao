//
// Created by syh on 19-3-14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

bool check(vector<int> num) {
    return (num[0] + num[1] == num[2]) && (num[3] - num[4] == num[5])
           && (num[6] * num[7] == num[8]) && (num[9] / num[10] == num[11]);
}

void f(int level, vector<int> num) {
    if (level == 12) {
        if (check(num))
            ans++;
        return;
    }

    if (level == 2) {
        if (num[0] + num[1] > 13) return;
    }
    if (level == 5) {
        if (num[3] - num[4] <= 0) return;;
    }
    if (level == 8) {
        if (num[6] * num[7] > 13) return;
    }
    if (level == 11)
        if (num[9] % num[10] != 0)return; // 注意除法截断，必须能整除

    for (int i = 1; i <= 13; i++) {
        if (find(num.begin(), num.end(), i) != num.end())  // 该数字已出现
            continue;
        if (level == 2 && i != (num[0] + num[1])) continue;
        if (level == 5 && i != (num[3] - num[4])) continue;
        if (level == 8 && i != (num[6] * num[7])) continue;
        if (level == 11 && i != (num[9] / num[10])) continue;
        num.push_back(i);
        f(level + 1, num);
        num.erase(num.end() - 1);
    }
}

int main() {
    vector<int> num;
    f(0, num);
    cout << ans << endl;
    return 0;
}