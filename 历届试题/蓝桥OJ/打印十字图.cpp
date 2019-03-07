#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int side = 4 * n + 5; // 总是奇数

    // 初始化背景
    char a[130][130];
    for (int i = 1; i <= side; i++) {
        for (int j = 1; j <= side; j++)
            a[i][j] = '.';
    }

    int mid = side / 2 + 1; // 无论n奇偶，mid总是中间
    // 中间十字架
    for (int i = mid - 2; i <= mid + 2; i++) {
        a[i][mid] = '$';
        a[mid][i] = '$';
    }

    // 边框十字架
    int tn = n;
    while (tn) {
        int tSide = 4 * n + 5;

        for (int i = mid - 2 * tn; i <= mid + 2 * tn; i++) {
            a[mid - 2 * (tn + 1)][i] = '$'; // 第一行
            a[mid + 2 * (tn + 1)][i] = '$'; // 最后一行
            a[i][mid - 2 * (tn + 1)] = '$'; // 第一列
            a[i][mid + 2 * (tn + 1)] = '$'; // 最后一列
        }

        // 第二行和倒数第二行，第二列和倒数第二列
        a[mid - 2 * tn - 1][mid - 2 * tn] = '$'; // 第二行
        a[mid - 2 * tn - 1][mid + 2 * tn] = '$';
        a[mid + 2 * tn + 1][mid - 2 * tn] = '$'; // 倒数第二行
        a[mid + 2 * tn + 1][mid + 2 * tn] = '$';
        a[mid - 2 * tn][mid - 2 * tn - 1] = '$'; // 第二列
        a[mid + 2 * tn][mid - 2 * tn - 1] = '$';
        a[mid - 2 * tn][mid + 2 * tn + 1] = '$'; // 倒数第二列
        a[mid + 2 * tn][mid + 2 * tn + 1] = '$';

        // 四个拐角
        a[mid - 2 * tn][mid - 2 * tn] = '$';
        a[mid - 2 * tn][mid + 2 * tn] = '$';
        a[mid + 2 * tn][mid - 2 * tn] = '$';
        a[mid + 2 * tn][mid + 2 * tn] = '$';

        // 上一层
        tn--;
    }

    // 输出
    for (int i = 1; i <= side; i++) {
        for (int j = 1; j <= side; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}