#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int line;
    cin >> line;
    vector<int> v;
    int t;
    while (cin >> t)
        v.push_back(t);
    sort(v.begin(), v.end());
    int m = 0, n = 0;
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) // 蓝桥杯评测不支持C++11，不要使用auto...
    {
        int delta = *(i + 1) - *i;
        if (delta == 2)
            m = *i + 1;// 缺号
        if (delta == 0)
            n = *i;// 重号
        if (m && n)
            break;
    }
    cout << m << " " << n << endl;
    return 0;
}
