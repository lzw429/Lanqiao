//
// Created by syh on 19-3-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << '\n';
    return 0;
}
