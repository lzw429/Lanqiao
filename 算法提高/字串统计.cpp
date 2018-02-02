#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L;
    string S;
    cin >> L >> S;
    vector <string> vec;
    int size = S.size();
    for (int i = L; i < size; i++) {
        for (int j = 0; j <= size - i; j++) {
            vec.push_back(S.substr(j, i)); // substr的参数：pos, len
        }
    }

    int max = 0; // 最多出现的次数
    int k = 0; // 出现最多的字符串的索引
    vector<int> times(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (i != j && vec[i] == vec[j])
                times[i]++;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        if (times[i] > max || (times[i] == max && vec[i].length() > vec[k].length())) {
            k = i;
            max = times[i];
        }
    }
    cout << vec[k];
    return 0;
}
