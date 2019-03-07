/*
 * 采用树状数组求逆序对
 * 每个小朋友交换的次数 = 左边更高和右边更矮的小朋友个数
 */
#include <iostream>
#include <cstring>

#define N 1000000
using namespace std;
int a[N]; // 输入数据
int c[N];
long long cha[N]; // 交换次数

int lowbit(int t) {
    return t & (-t);
}

int sum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

void add(int x, int val) {
    for (int i = x; i < N; i += lowbit(i))
        c[i] += val;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(a[i] + 1, 1);
        cha[i] = (i + 1) - sum(a[i] + 1); // 左边逆序对
    }
    memset(c, 0, sizeof(c));
    // 右边逆序对
    for (int i = n - 1; i >= 0; i--) {
        add(a[i] + 1, 1);
        cha[i] += sum(a[i]);
    }
    // 由交换次数计算不高兴值
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += (1 + cha[i]) * cha[i] / 2;
    cout << ans;
    return 0;
};
