//
// Created by syh on 19-3-23.
//

#include <iostream>
#include <sstream>

using namespace std;

string f(int n) {
    if (n == 1) return "A";

    stringstream ss;
    string res;
    ss << f(n - 1) << (char) (n - 1 + 'A') << f(n - 1);
    ss >> res;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}