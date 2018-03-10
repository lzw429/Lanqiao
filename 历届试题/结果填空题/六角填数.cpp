/*
六角填数

    如图【1.png】所示六角形中，填入1~12的数字。

    使得每条直线上的数字之和都相同。

    图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？

 */

#include <iostream>
#include<set>

using namespace std;

bool vis[15];

void DFS(int nums[], int step) {
    if (step == 9) {
        set<int> s;
        s.insert(nums[2] + nums[3] + nums[4] + nums[5]);
        s.insert(nums[1] + nums[3] + nums[6] + nums[8]);
        s.insert(nums[1] + nums[4] + nums[7] + nums[11]);
        s.insert(nums[8] + nums[9] + nums[10] + nums[11]);
        s.insert(nums[2] + nums[6] + nums[9] + nums[12]);
        s.insert(nums[5] + nums[7] + nums[10] + nums[12]);
        if (s.size() == 1)
            cout << nums[6] << endl;
        return;
    } else {
        for (int i = 2; i <= 12; i++) {
            if (!vis[i]) {
                vis[i] = true;
                nums[step + 3] = i;
                DFS(nums, step + 1);
                vis[i] = false;
            }
        }
    }
}

int main() {
    int nums[15] = {};
    nums[1] = 1;
    nums[2] = 8;
    nums[12] = 3;
    vis[1] = true;
    vis[8] = true;
    vis[3] = true;
    // 求nums[6]？从nums[3]填数至nums[11]
    // 六条直线: 2 3 4 5; 1 3 6 8; 1 4 7 11; 8 9 10 11; 2 6 9 12; 5 7 10 12
    DFS(nums, 0);
    return 0;
}