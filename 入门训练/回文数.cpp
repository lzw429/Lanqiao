#include <iostream>

using namespace std;

int main() {
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= 9; c++)
                for (int d = 0; d <= 9; d++) {
                    if (a == d && b == c)
                        cout << 1000 * a + 100 * b + 10 * c + d << endl;
                }
    return 0;
}
