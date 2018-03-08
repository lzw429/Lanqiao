#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    const int size = str.size();
    int dec = 0;
    for (int i = 0; i != size; i++) {
        int cur;
        if (str[i] >= 'A' && str[i] <= 'F')
            cur = str[i] - 'A' + 10;
        else if (str[i] >= '0' && str[i] <= '9')
            cur = str[i] - '0';
        dec = dec * 16 + cur;
    }
    cout << "Hex: 0x" << str << endl;
    cout << "Decimal: " << dec << endl;
    printf("Octal: %04o\n", dec);
    return 0;
}
