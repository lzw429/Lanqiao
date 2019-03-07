/*
【题目描述】
你有一张某海域NxN像素的照片，"."表示海洋、"#"表示陆地，如下所示：

.......
.##....
.##....
....##.
..####.
...###.
.......

其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。

例如上图中的海域未来会变成如下样子：

.......
.......
.......
.......
....#..
.......
.......

请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。

【输入格式】
第一行包含一个整数N。 (1 <= N <= 1000)
以下N行N列代表一张海域照片。

照片保证第1行、第1列、第N行、第N列的像素都是海洋。

【输出格式】
一个整数表示答案。

【样例输入】
7
.......
.##....
.##....
....##.
..####.
...###.
.......

【样例输出】
1


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗 < 1000ms
*/

// 不要使用淹没前的海岛数减去淹没后的海岛数量，因为某些海岛在淹没后可能变为两个
#include <cstring>
#include <iostream>

using namespace std;

#define MAXN 1000 + 5
int map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n;

int DFS(int i, int j) {
  // 如果有一块陆地的四周皆为陆地，则不会被淹没，返回 0
  // 否则会被淹没，返回 1
  bool flag = false;
  if ((i < n - 1 && map[i + 1][j] == 0) || (i > 0 && map[i - 1][j] == 0) ||
      (j > 0 && map[i][j - 1] == 0) || (j < n - 1 && map[i][j + 1] == 0))
    return 0;
  if (i < n - 1 && !vis[i + 1][j]) {
    vis[i + 1][j] = true;
    if (DFS(i + 1, j))
      flag = true;
  }
  if (j < n - 1 && !vis[i][j + 1]) {
    vis[i][j + 1] = true;
    if (DFS(i, j + 1))
      flag = true;
  }
  if (i > 0 && !vis[i - 1][j]) {
    vis[i - 1][j] = true;
    if (DFS(i - 1, j))
      flag = true;
  }
  if (j > 0 && !vis[i][j - 1]) {
    vis[i][j - 1] = true;
    if (DFS(i, j - 1))
      flag = true;
  }
  return flag ? 0 : 1;
}

int main() {
  int res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < n; j++) {
      if (line[j] == '#')
        map[i][j] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] && !vis[i][j]) {
        vis[i][j] = true;
        res += DFS(i, j); // 计算淹没小岛数
      }
    }
  }
  cout << res;
  return 0;
}
