/*
���⣺������

    ��ͼp1.jpg��ʾ��3 x 3 �ĸ�������д��һЩ������

    ��������ͼ�еĺ�ɫ�߼������õ��������֣�ÿ�����ֵ����ֺͶ���60��

    �����Ҫ������������ж����Ը�����m x n �ĸ����е��������Ƿ���Էָ�Ϊ�������֣�ʹ����������������ֺ���ȡ�
    ������ڶ��ֽ��������������ϽǸ��ӵ��Ǹ���������ĸ��ӵ���С��Ŀ��   
    ����޷��ָ����� 0

�������������ʽҪ��
�����ȶ����������� m n �ÿո�ָ� (m,n<10)
��ʾ���Ŀ�Ⱥ͸߶�
��������n�У�ÿ��m�����������ÿո�ֿ���ÿ������������10000
��������������н��У��������Ͻǵķָ������ܰ�������С�ĸ�����Ŀ��


���磺
�û����룺
3 3
10 1 52
20 30 1
1 2 3

����������
3

�����磺
�û����룺
4 3
1 1 1 1
1 30 80 2
1 1 1 100

����������
10

(�μ�p2.jpg)


��ԴԼ����
��ֵ�ڴ����� < 64M
CPU����  < 5000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int m, n; // ���������� 
int g[10][10];
int total;

class Cut { // һ�ּ����ӷ��� 
public:
    set<pair<int, int> > grids; // �������ɸ���
    int sum; // ���и��ӵ���ֵ�� 

    Cut() {}

    Cut(Cut &cut) {
        this->sum = cut.sum;

        for (set<pair<int, int> >::iterator i = cut.grids.begin(); i != cut.grids.end(); i++) {
            this->grids.insert(*i);
        }
    }
};

vector<Cut *> cuts[100]; // �ֱ�洢������Ϊ1~100�ĸ��ּ��� 

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

    // ���� 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            total += g[i][j];
        }
    }

    // ��һ�����Ӵﵽһ��
    if (g[0][0] == total / 2) {
        cout << 1;
        return 0;
    }

    Cut *c = new Cut(); // һ�ּ��� 
    const pair<int, int> p(0, 0); // ���ϽǸ���
    c->grids.insert(p);
    c->sum = g[0][0];
    cuts[1].push_back(c); // ֻ����һ�������Ҹø���Ϊ(0, 0)��ֻ����һ�ּ���

    for (int i = 2; i < m * n; i++) {
        // i �Ǹ��������� cuts[i-1] �еļ��������� cuts[i] 
        for (int j = 0; j < cuts[i - 1].size(); j++) {
            // ������������Ϊ i - 1 �����м��� 
            Cut *pCut = cuts[i - 1][j];
            set<pair<int, int> > &grids = pCut->grids;
            int sum = pCut->sum;

            for (set<pair<int, int> >::iterator it = grids.begin(); it != grids.end(); it++) {
                // ����ÿ������ 
                const pair<int, int> &p = *it;
                int x = p.first; // ���� p->first 
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
