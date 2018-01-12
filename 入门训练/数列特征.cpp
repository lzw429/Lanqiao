#include <iostream>
#include <climits>

using namespace std;

int main() {
    int min = INT_MAX;
    int max = INT_MIN;
    int n;
    int t;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > max)
            max = t;
        if (t < min)
            min = t;
        sum += t;
    }
    cout << max << endl << min << endl << sum;
	return 0;
}
