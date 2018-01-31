#include <iostream>

using namespace std;

class Time {
public:
    int hour, minute, second;

    Time(int hour, int minute, int second) {
        int t = (3600 * hour + 60 * minute + second) % 86400;
        if (t < 0)
            t = 86400 + t;
        this->hour = t / 3600;
        this->minute = (t % 3600) / 60;
        this->second = t % 3600 % 60;
    }

    void adv(int incr_hr, int incr_min, int incr_sec) {
        int cur = 3600 * hour + 60 * minute + second;
        int add = 3600 * incr_hr + 60 * incr_min + incr_sec;
        int res = (cur + add) % 86400;
        if (res < 0)
            res = 86400 + res;
        hour = res / 3600;
        minute = (res % 3600) / 60;
        second = res % 3600 % 60;
    }

    void reset() {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }

    void print() {
        printf("%02d:%02d:%02d\n", this->hour, this->minute, this->second);
    }
};

int main() {
    int hour, minute, second, incr_hr, incr_min, incr_sec;
    cin >> hour >> minute >> second >> incr_hr >> incr_min >> incr_sec;
    Time t(hour, minute, second);
    t.print();
    t.adv(incr_hr, incr_min, incr_sec);
    t.print();
    t.reset();
    t.print();
    return 0;
}
