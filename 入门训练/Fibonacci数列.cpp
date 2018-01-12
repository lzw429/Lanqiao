#include<iostream>

using namespace std;
int Fib[1000010];

int main() {
    int n;
    cin >> n;

    Fib[0] = Fib[1] = 1;
    for (int i = 2; i != 1000001; ++i) {
        Fib[i] = (Fib[i - 1] + Fib[i - 2]) % 10007;
    }
    cout << Fib[n - 1];
    return 0;
}


