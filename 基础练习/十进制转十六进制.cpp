#include<iostream>

using namespace std;
char h[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int res[100000];

int main() {
    int n;
    int k = 0;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    while (n) {
        res[k++] = n % 16;
        n /= 16;
    }
    for (int i = k - 1; i >= 0; i--) {
        printf("%c", h[res[i]]);
    }
    printf("\n");
    return 0;
}
