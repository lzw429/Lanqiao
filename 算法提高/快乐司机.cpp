#include <iostream>
#include <queue>

using namespace std;

struct Cargo {
    int value; // 价值
    int weight; // 重量
    double unit; // 单价
    bool operator<(const Cargo &c) const {
        return this->unit < c.unit; // 较大值优先
    }
};

int main() {
    int n, w;
    cin >> n >> w;
    priority_queue <Cargo> pq;
    double res = 0;
    for (int i = 0; i < n; i++) {
        int gi, pi;
        cin >> gi >> pi;
        double unit = (double) pi / gi;
        pq.push(Cargo{pi, gi, unit});
    }
    while (w != 0) {
        Cargo cur = pq.top();
        pq.pop();
        if (w >= cur.weight) {
            w -= cur.weight;
            res += cur.value;
        } else //if (w < cur.weight)
        {
            res += (double) w * cur.unit;
            break;
        }
    }

    printf("%.1f", res);
    return 0;
}
