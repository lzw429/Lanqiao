#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i < 32; i++) {
        for (int j = 1; j < 32; j++) {
            for (int k = 1; k < 32; k++) {
                if (j != i && k != i && k != j)
                if (i * i + j * j + k * k == 1000) {
                    cout << i << " " << j << " " << k << " " << endl;
                }
            }
        }
    }
    return 0;
}
