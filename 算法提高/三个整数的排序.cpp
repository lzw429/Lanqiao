#include<iostream>
#include<queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    int a, b, c;
    cin >> a >> b >> c;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    for (int i = 0; i <= 2; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
