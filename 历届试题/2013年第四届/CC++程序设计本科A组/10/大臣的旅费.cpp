/*

标题：大臣的旅费


    很久以前，T王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。

    为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。

    J是T国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。他有一个钱袋，用于存放往来城市间的路费。

    聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。

    J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？

输入格式：
输入的第一行包含一个整数n，表示包括首都在内的T王国的城市数
城市从1开始依次编号，1号城市为首都。
接下来n-1行，描述T国的高速路（T国的高速路一定是n-1条）
每行三个整数Pi, Qi, Di，表示城市Pi和城市Qi之间有一条高速路，长度为Di千米。

输出格式:
输出一个整数，表示大臣J最多花费的路费是多少。

样例输入:
5
1 2 2
1 3 1
2 4 5
2 5 4

样例输出:
135

样例说明:
大臣J从城市4到城市5要花费135的路费。


根据资源限制尽可能考虑支持更大的数据规模。


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

using namespace std;

class Edge {
public:
    int to;
    int dis;
};

const int maxn = 100010;
bool vis[maxn];
vector<Edge> g[maxn];
int maxSize;
int ansNode;
int ansDis = -1;

void dfs(int node, int dis) {
    // 找到树中距离node最远的点的距离 
    
    if (dis > ansDis) {
        ansDis = dis;
        ansNode = node;
    }
    
    vis[node] = true;
    vector<Edge> &edges = g[node];
    for (int i = 0; i < edges.size(); i++) {
        int to = edges[i].to;
        if(vis[to] == false) {
            dfs(to, dis + edges[i].dis);
        }
    }
    vis[node] = false;
}

int main() {
    int n;
    cin >> n;
    int from, to, dis;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> dis;
        struct Edge e1 = {to, dis}; 
        struct Edge e2 = {from, dis};
        g[from].push_back(e1);
        g[to].push_back(e2);
    }
    
    dfs(1, 0); // 1号为首都
    ansDis = -1; 
    dfs(ansNode, 0);
    // cout << ansNode << endl;
    // cout << ansDis << endl;
    cout << (11 + 10 + ansDis) * ansDis / 2;
    return 0;
} 
