#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

int main() {
    int t;
    while (cin >> t) {
        if (t == 0)break;
        vec.push_back(t);
    }
    for (vector<int>::reverse_iterator i = vec.rbegin(); i != vec.rend(); ++i) {
        cout << *i << " ";
    }
    return 0;
}
