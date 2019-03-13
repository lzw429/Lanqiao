#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string intToStr(int num) {
    stringstream ss;
    ss << num;
    string res;
    ss >> res;
    return res;
}

bool check(int i2, int i3) {
    string i2str = intToStr(i2);
    string i3str = intToStr(i3);
    if(i2str.size() + i3str.size() != 10) return false;
    string concat = i2str + i3str;
    sort(concat.begin(), concat.end());
    for(int i = 1; i < concat.size(); i++) {
        if(concat[i] == concat[i - 1])
            return false;
    }
    return true;
}

int main() {
    for (int i = 0; i < 10000; i++) {
         int i2 = i * i;
         int i3 = i2 * i;
         if(check(i2, i3))
            cout << i << " " << i2 << " " << i3 << endl;
    }
    return 0;
}
