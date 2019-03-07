#include <iostream>

#define  MAXN 1000
using namespace std;

string s1, s2;
int ans;

void change(char &c) {
    if (c == 'o')
        c = '*';
    else if (c == '*')
        c = 'o';
}

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length() - 1; i++) {
        if (s1[i] != s2[i]) {
            ans++;
            change(s1[i]);
            change(s1[i + 1]);
        }
    }
    cout << ans;
    return 0;
}