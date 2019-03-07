#include <iostream>
#include <algorithm>
#include <vector>

#define  MAXN 100010
using namespace std;

struct Node {
    int u, v, day;
};
vector <Node> ver;
int F[MAXN]; // 用于并查集

int find(int x) {
    if (F[x] == x)
        return x;
    else return F[x] = find(F[x]);
}

bool add(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        F[u] = v;
        return true;
    }
    return false;
}

bool cmp(Node n1, Node n2) {
    return n1.day > n2.day;
}

int main() {
    int n, m, ans = 0;
    cin >> n >> m; // 岛与桥的数量
    for (int i = 0; i != m; i++) {
        int u, v, day;
        cin >> u >> v >> day;
        ver.push_back(Node{u, v, day});
    }
    for (int i = 0; i != MAXN; i++)
        F[i] = i; // 并查集初始化
    sort(ver.begin(), ver.end(), cmp);
    int pre = -1; // 上一次抗议的天数
    for (int i = 0; i != m; ++i) {
        if (add(ver[i].u, ver[i].v) && pre != ver[i].day) {
            ans++;
            pre = ver[i].day;
        }
    }
    cout << ans;
    return 0;
}
