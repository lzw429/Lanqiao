/*
某涉密单位下发了某种票据，并要在年终全部收回。

每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。

因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。

你的任务是通过编程，找出断号的ID和重号的ID。

假设断号不可能发生在最大和最小号。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int line;
    cin >> line;
    vector<int> v;
    int t;
    while (cin >> t)
        v.push_back(t);
    sort(v.begin(), v.end());
    int m = 0, n = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        int delta = v[i + 1] - v[i];
        if (delta == 2) // 缺号
            m = v[i] + 1;
        else if (delta == 0) // 重号
            n = v[i];
        if (m && n)
            break;
    }
    cout << m << " " << n << endl;
    return 0;
}
