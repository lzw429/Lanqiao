#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= 9; c++)
                for (int d = 0; d <= 9; d++)
                    for (int e = 0; e <= 9; e++) {
                        int num = 10000 * a + 1000 * b + 100 * c + 10 * d + e;
                        int sum = a + b + c + d + e;
                        if (sum == n && a == e && b == d)
                            cout << num << endl;
                    }
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= 9; c++)
                for (int d = 0; d <= 9; d++)
                    for (int e = 0; e <= 9; e++)
                        for (int f = 0; f <= 9; f++) {
                            int num = 100000 * a + 10000 * b + 1000 * c + 100 * d + 10 * e + f;
                            int sum = a + b + c + d + e + f;
                            if (sum == n && a == f && b == e && c == d)
                                cout << num << endl;
                        }
    return 0;
}
