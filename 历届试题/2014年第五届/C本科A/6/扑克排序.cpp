#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string cards = "11223344"; // ��ĸ�޷�ֱ�Ӻ��������Ƚϣ���Ҫ��д�ȽϺ��� 
    do {
        if(cards.find("1") + 2 == cards.rfind("1") &&
           cards.find("2") + 3 == cards.rfind("2") &&
           cards.find("3") + 4 == cards.rfind("3") &&
           cards.find("4") + 5 == cards.rfind("4")) {
               cout << cards << endl;
        }
    } while (next_permutation(cards.begin(), cards.end()));
    return 0;
} 

// ��2342A3A4
