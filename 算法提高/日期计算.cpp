#include <iostream>

using namespace std;

bool isLeap(int n) // 判断闰年
{
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
        return true;
    return false;
}

int md[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int year, month, day;
    int sum = 0;
    cin >> year >> month >> day; // 2017年1月1日是周日，计算与这天的距离
    if (year >= 2017) {
        for (int i = 2017; i < year; i++) {
            sum += 365;
            if (isLeap(i))
                sum++;
        }
        for (int i = 1; i < month; i++) {
            sum += md[i];
            if (i == 2 && isLeap(year))
                sum++;
        }
        sum += (day - 1);
        cout << ((sum % 7 == 0) ? 7 : (sum % 7)) << endl;
    } else if (year <= 2016) {
        int t = 0;
        for (int i = year; i < 2017; i++) {
            sum += 365;
            if (isLeap(i))
                sum++;
        }
        for (int i = 1; i < month; i++) {
            t += md[i];
            if (i == 2 && isLeap(year))
                t++;
        }
        t += (day - 1);
        sum -= t;
        cout << 7 - (sum % 7) << endl;
    }
    return 0;
}
