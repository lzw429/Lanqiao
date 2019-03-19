/*
标题：剪格子

    如图p1.jpg所示，3 x 3 的格子中填写了一些整数。

    我们沿着图中的红色线剪开，得到两个部分，每个部分的数字和都是60。

    本题的要求就是请你编程判定：对给定的m x n 的格子中的整数，是否可以分割为两个部分，使得这两个区域的数字和相等。
    如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。   
    如果无法分割，则输出 0

程序输入输出格式要求：
程序先读入两个整数 m n 用空格分割 (m,n<10)
表示表格的宽度和高度
接下来是n行，每行m个正整数，用空格分开。每个整数不大于10000
程序输出：在所有解中，包含左上角的分割区可能包含的最小的格子数目。


例如：
用户输入：
3 3
10 1 52
20 30 1
1 2 3

则程序输出：
3

再例如：
用户输入：
4 3
1 1 1 1
1 30 80 2
1 1 1 100

则程序输出：
10

(参见p2.jpg)


资源约定：
峰值内存消耗 < 64M
CPU消耗  < 5000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int m, n; // 列数，行数 
int g[10][10];
int total;

class Cut { // 一种剪格子方法 
public:
    set<pair<int, int> > grids; // 包含若干格子
    int sum; // 所有格子的数值和 

    Cut() {}

    Cut(Cut &cut) {
        this->sum = cut.sum;

        for (set<pair<int, int> >::iterator i = cut.grids.begin(); i != cut.grids.end(); i++) {
            this->grids.insert(*i);
        }
    }
};

vector<Cut *> cuts[100]; // 分别存储格子数为1~100的各种剪法 

bool check(int i, Cut *cut_new) {
    if (cut_new->sum == total / 2) {
        cout << i << endl;
        return true;
    } else if (cut_new->sum < total / 2) {
        cuts[i].push_back(cut_new);
    }
    return false;
}

int main() {
    cin >> m >> n;

    // 输入 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            total += g[i][j];
        }
    }

    // 第一个格子达到一半
    if (g[0][0] == total / 2) {
        cout << 1;
        return 0;
    }

    Cut *c = new Cut(); // 一种剪法 
    const pair<int, int> p(0, 0); // 左上角格子
    c->grids.insert(p);
    c->sum = g[0][0];
    cuts[1].push_back(c); // 只包含一个格子且该格子为(0, 0)的只有这一种剪法

    for (int i = 2; i < m * n; i++) {
        // i 是格子数，用 cuts[i-1] 中的剪法来生成 cuts[i] 
        for (int j = 0; j < cuts[i - 1].size(); j++) {
            // 遍历格子数量为 i - 1 的所有剪法 
            Cut *pCut = cuts[i - 1][j];
            set<pair<int, int> > &grids = pCut->grids;
            int sum = pCut->sum;

            for (set<pair<int, int> >::iterator it = grids.begin(); it != grids.end(); it++) {
                // 遍历每个格子 
                const pair<int, int> &p = *it;
                int x = p.first; // 不是 p->first 
                int y = p.second;

                if (x + 1 < n && grids.find(make_pair(x + 1, y)) == grids.end()) {
                    Cut *cut_new = new Cut(*pCut);
                    cut_new->grids.insert(make_pair(x + 1, y));
                    cut_new->sum += g[x + 1][y];
                    if (check(i, cut_new)) return 0;
                }

                if (x - 1 >= 0 && grids.find(make_pair(x - 1, y)) == grids.end()) {
                    Cut *cut_new = new Cut(*pCut);
                    cut_new->grids.insert(make_pair(x - 1, y));
                    cut_new->sum += g[x - 1][y];
                    if (check(i, cut_new)) return 0;
                }

                if (y - 1 >= 0 && grids.find(make_pair(x, y - 1)) == grids.end()) {
                    Cut *cut_new = new Cut(*pCut);
                    cut_new->grids.insert(make_pair(x, y - 1));
                    cut_new->sum += g[x][y - 1];
                    if (check(i, cut_new)) return 0;
                }

                if (y + 1 < m && grids.find(make_pair(x, y + 1)) == grids.end()) {
                    Cut *cut_new = new Cut(*pCut);
                    cut_new->grids.insert(make_pair(x, y + 1));
                    cut_new->sum += g[x][y + 1];
                    if (check(i, cut_new)) return 0;
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
