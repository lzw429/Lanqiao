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
int nLen = 0;

int substrInt(char *str, int start, int len) {
    int res = 0;
    for (int i = start; i < start + len; i++) {
        res *= 10;
        res += str[i] - '0';
    }
    return res;
}

bool check(char *nums, int sum) {
    for (int i = 1; i <= nLen; i++) {
        for (int j = (nums_size - i) / 2; j <= nums_size - i - 1; j++) {
            int a = substrInt(nums, 0, i);
            int b = substrInt(nums, i, j);
            int c = substrInt(nums, i + j, nums_size - i - j);
            if (a >= sum) 
                return false;
            if(b % c == 0 && sum * c == a * c + b) {
                // cout << a <<" "<< b<< " " << c << " " << endl;
                return true;                
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int m = n;
    while(m) {
        nLen++;
        m /= 10;
    }
    int cnt = 0;
    char nums[15] = "123456789";
    do {
        if (check(nums, n)== true) {
            cnt++;
        }
    } while (next_permutation(nums, nums + 9));
    cout << cnt << endl;
    return 0;
}

