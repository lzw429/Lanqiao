#include <iostream>
#include<vector>

using namespace std;

string express(int);

int main() {
    int n;
    while (cin >> n)  // n∈[1, 20000]
    {
        cout << express(n) << endl;;
    }
    return 0;
}

string express(int n) {
    string res;
    if (n == 0)
        return "0";
    else if (n == 1)
        return "2(0)";
    else if (n == 2)
        return "2";
    vector<int> bits;
    int i = 0;
    while (n > 0) {
        if (n & 1)
            bits.push_back(i);
        n = n >> 1;
        i++;
    }
    for (int j = bits.size() - 1; j >= 0; j--) {
        string e = express(bits[j]);
        if (j == bits.size() - 1) {
            if (bits[j] == 1) // 直接输出2而不是2(2(0))
                res += "2";
            else res += "2(" + e + ")";
        } else {
            if (bits[j] == 1)
                res += "+2";
            else res += "+2(" + e + ")";
        }
    }
    return res;
}
