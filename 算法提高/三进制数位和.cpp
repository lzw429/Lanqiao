#include <iostream>

using namespace std;

int main() {
    int L, R, cnt = 0;
    cin >> L >> R;
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            for (int c = 0; c < 3; c++)
                for (int d = 0; d < 3; d++)
                    for (int e = 0; e < 3; e++)
                        for (int f = 0; f < 3; f++) {
                            int S = a + b + c + d + e + f;
                            if (S >= L && S <= R || S == 2 || S == 3 || S == 5 || S == 7 || S == 11)
                                cnt++;
                        }
    cout << cnt;
}
