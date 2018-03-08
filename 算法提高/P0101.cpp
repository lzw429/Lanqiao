#include <iostream>

using namespace std;

int main() {
    double quart;
    cin >> quart;
    double quotient = 950 / 3E-23;
    printf("%E", quart * quotient); // 科学计数法输出
    return 0;
}
