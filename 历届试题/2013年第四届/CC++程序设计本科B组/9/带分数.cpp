/*

���⣺������

    100 ���Ա�ʾΪ����������ʽ��100 = 3 + 69258 / 714

    �����Ա�ʾΪ��100 = 82 + 3546 / 197

    ע���������������У�����1~9�ֱ������ֻ����һ�Σ�������0����

    ���������Ĵ�������100 �� 11 �ֱ�ʾ����

��ĿҪ��
�ӱ�׼�������һ��������N (N<1000*1000)
�������������������1~9���ظ�����©����ɴ�������ʾ��ȫ��������
ע�⣺��Ҫ�����ÿ����ʾ��ֻͳ���ж��ٱ�ʾ����


���磺
�û����룺
100
���������
11

�����磺
�û����룺
105
���������
6


��ԴԼ����
��ֵ�ڴ����� < 64M
CPU����  < 3000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�


  
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>

using namespace std;

const int nums_size = 9;
int nLen;

int strToInt(string str) {
    int res;
    stringstream ss;
    ss << str;
    ss >> res;
    return res;
}

char* intToStr(int num) {
    char str[9] = {};
    sprintf(str, "%d", num);
    return str;
}

bool check(const string &nums, int sum) {
    for (int i = 1; i <= nLen; i++) {
        for (int j = (nums_size - i) / 2; j <= nums_size - i - 1; j++) {
            int a = strToInt(nums.substr(0, i));
            int b = strToInt(nums.substr(i, j));
            int c = strToInt(nums.substr(i + j, nums_size - i - j));
            if (a >= sum) 
                return false;
            if(b % c == 0 && sum * c == a * c + b) {
                cout << a <<" "<< b<< " " << c << " " << endl;
                return true;                
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    nLen = intToStr(n).size();
    int cnt = 0;
    string nums = "123456789"; 
    do {
        if (check(nums, n)== true) {
            cnt++;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << cnt << endl;
    return 0;
}
