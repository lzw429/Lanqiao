#include <iostream>

using namespace std;

int main() {
    int cnt = 0;
    for (int age = 10; age < 100; age++) {
        int a1 = age / 10;
        int a2 = age % 10;
        if ((a2 * 10 + a1) == (age - 27)) {
            cout << age << " " << age - 27 << endl;
            cnt++;
        }
    }
    cout << "The total number is " << cnt << endl;
    return 0;
}
