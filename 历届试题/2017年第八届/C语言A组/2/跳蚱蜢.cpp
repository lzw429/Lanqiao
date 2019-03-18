//
// Created by syh on 19-3-16.
//


// 本题考察广度优先搜索 BFS

#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int size = 9;
string start = "012345678";
string target = "087654321";
queue<string> que;
int len = 0, pos;
map<string, bool> vis;

/**
 * 找到空位索引
 * @param str
 * @return str 中的空位索引
 */
int findZero(string &str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0')
            return i;
    }
    return -1;
}

int main() {
    que.push(start);
    que.push("0");
    vis[start] = true;
    while (!que.empty()) {
        string cur = que.front();
        que.pop();

        if (target == cur)
            break;
        if (cur == "0") {
            len++;
            if (!que.empty()) {
                que.push("0");
                continue;
            } else break;
        }

        pos = findZero(cur);
        string s1(cur);
        swap(s1[pos], s1[(pos + 1 + size) % size]);
        if (!vis[s1]) {
            vis[s1] = true;
            que.push(s1);
        }
        string s2(cur);
        swap(s2[pos], s2[(pos - 1 + size) % size]);
        if (!vis[s2]) {
            vis[s2] = true;
            que.push(s2);
        }
        string s3(cur);
        swap(s3[pos], s3[(pos + 2 + size) % size]);
        if (!vis[s3]) {
            vis[s3] = true;
            que.push(s3);
        }
        string s4(cur);
        swap(s4[pos], s4[(pos - 2 + size) % size]);
        if (!vis[s4]) {
            vis[s4] = true;
            que.push(s4);
        }
    }
    cout << len << endl;
}