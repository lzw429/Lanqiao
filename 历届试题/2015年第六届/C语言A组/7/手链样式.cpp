// ȫ���У�����ȥ��
// ���ظ�Ԫ�ص�Բ�����뻷���еļ������� 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

int main() {
    string s = "aaabbbbccccc";
    vector<string> v1;

    do {
        // �ų��ظ�������v1�е�ÿ��Ԫ�ؽ��м��
        // �������s����ת���߷�ת�������� 
        int i = 0;
        for (; i < v1.size(); i++) {
            if (v1[i].find(s) != string::npos) // ��ͨ��ת���򷭶��ص�֮ǰ�����ɵ���ʽ
                break;
        }
        if (i != v1.size()) // s �����õ���� 
            continue;

        // s ���ã��ҵ�һ������ʽ��������¼��ֹ�����ظ�
        string s2 = s + s;
        v1.push_back(s2);
        reverse(s2.begin(), s2.end());
        v1.push_back(s2);

        ans++;
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;
    return 0;
}
