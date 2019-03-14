#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, bool> mp;
vector<int> cardNum;
int cnt;

bool check(string str) {
    sort(str.begin(), str.end());
    if(mp[str] == false) return true;
    else mp[str] = true;
    return false;
}

void f(int level, string str) {
    if(level == 13) {
        if(check(str) == true)
            cnt++;
        return;
    }
    
    for(int i = 0; i < cardNum.size(); i++) {
        if(cardNum[i] > 0) {
            cardNum[i]--;
            char ch = 'A' + i;
            str.push_back(ch);
            f(level + 1, str);
            str.erase(str.end() - 1);
            cardNum[i]++;
        }
    }
    cout << str << endl;
}

int main() {
    // 13种牌，每种牌有4张 
    string cards;
    int cnt = 0;
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 4; j++) {
            char ch = 'A' + i;
            cards.push_back(ch);
        }
    }
    
    for(int i = 0; i < 13; i++) {
        cardNum.push_back(4);
    }
    
    f(0, "");
    cout << cnt << endl;
    return 0;
}
