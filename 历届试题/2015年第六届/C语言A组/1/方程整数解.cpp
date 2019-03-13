#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 32; k++) {
                if (j != i && k != i && k != j)
                if (i * i + j * j + k * k == 1000) {
                    cout << i << " " << j << " " << k << " " << endl;
                }
            }
        }
    }
    return 0;
}
