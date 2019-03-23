// 全排列，特殊去重
// 有重复元素的圆排列与环排列的计数问题 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

int main() {
    string s = "aaabbbbccccc";
    vector<string> v1;

    do {
        // 排除重复，对于v1中的每个元素进行检查
        // 如果存在s的旋转或者翻转，则跳过 
        int i = 0;
        for (; i < v1.size(); i++) {
            if (v1[i].find(s) != string::npos) // 可通过转动或翻动回到之前已生成的样式
                break;
        }
        if (i != v1.size()) // s 不可用的情况 
            continue;

        // s 可用，找到一种新样式，将它记录防止后续重复
        string s2 = s + s;
        v1.push_back(s2);
        reverse(s2.begin(), s2.end());
        v1.push_back(s2);

        ans++;
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;
    return 0;
}
