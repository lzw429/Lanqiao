#include <iostream>
#include<cmath>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    double c = sqrt(a * a + b * b);
    printf("%.1f+%.1fi", a / c, b / c);
    return 0;
}
