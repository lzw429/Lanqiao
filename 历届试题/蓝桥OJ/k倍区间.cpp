/*
k倍区间

给定一个长度为N的数列，A1, A2, ... AN，如果其中一段连续的子序列Ai, Ai+1, ... Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。

你能求出数列中总共有多少个K倍区间吗？

输入
-----
第一行包含两个整数N和K。(1 <= N, K <= 100000)
以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)

输出
-----
输出一个整数，代表K倍区间的数目。


例如，
输入：
5 2
1
2
3
4
5

程序应该输出：
6

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
 */

#include <iostream>
#include <set>

#define MAXN 100010

using namespace std;

int n, k;
long long a[MAXN];
long long b[MAXN];
long long ans;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        a[i] = (a[i - 1] + a[i]) % k; // 累加
    }
    for (int i = 0; i < n; ++i) {
        // b[a[i]]记录a数组前i-1个与a[i]值相同的数量
        ans += (b[a[i]]++);
    }
    cout << ans + b[0];
    return 0;

}
