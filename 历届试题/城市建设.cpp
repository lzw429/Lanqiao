#include <iostream>
#include <algorithm>

#define MAXN 100000 // 最大顶点数
#define MAXM 1000000 // 最大边数
using namespace std;

int F[MAXN]; // 并查集使用

struct Edge {
    int u;
    int v;
    int w;
} edge[MAXM];

int tol = 0; // 边数

void addEdge(int u, int v, int w) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
    return;
}

bool cmp(Edge a, Edge b) {
    // 排序函数，将边按照权值从小到大排序
    return a.w < b.w;
}

int find(int x) {
    if (F[x] == x)
        return x;
    else
        return F[x] = find(F[x]);
}

int Kruskal(int n) // 传入顶点数，返回最小生成树的权值，若不连通返回-1
{
    for (int i = 0; i <= n; i++)
        F[i] = i; // 初始状态每个顶点是一棵子树
    sort(edge, edge + tol, cmp);

    int cnt = 0; // 计算加入的边数
    int ans = 0;
    for (int i = 0; i < tol; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo) // 如果u和v当前不是在一棵子树上
        {
            ans += w;
            F[tOne] = tTwo;
            cnt++; // 加入一条边到生成树
        } else if (w < 0) // 如果这条路赚钱，即使多余也要修
            ans += w;
    }
    if (cnt < n - 1)
        return -1;
    return ans;
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m; // n是顶点数，m是道路数
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    int noPort = Kruskal(n);

    for (int i = 1; i <= n; i++) {
        cin >> w;
        if (w != -1) // t若小于0则不建设码头
            addEdge(0, i, w); // 河道作为0号点
    }
    if (noPort == -1)   // 如果不修建码头不能连通，则必须修建码头
        cout << Kruskal(n + 1);
    else                // 如果不修建码头能连通，则需要比较修建与不修建的费用
        cout << min(Kruskal(n + 1), noPort);
    return 0;
}
