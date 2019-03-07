#include <iostream>

using namespace std;

int cnt;

bool check_digit(int digit, int a, int b, int c, int d) {
    if(digit != a && digit != b && digit != c && digit != d) return false;
    return true;
}

bool check(int product, int a, int b, int c, int d) {
    if(product < 1023 || product > 9876) return false;
    int n1 = product / 1000 % 10; // 千位 
    int n2 = (product / 100) % 10; // 百位 
    int n3 = (product / 10) % 10; // 十位 
    int n4 = product % 10; // 个位 
    
    if (n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4)
        return false;
    if(!check_digit(n1, a, b, c, d) || !check_digit(n2, a, b, c, d) ||
       !check_digit(n3, a, b, c, d) || !check_digit(n4, a, b, c, d)) return false;  
    
    cnt++; 
    return true;
}

int main() {
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            if(b != a)
                for (int c = 0; c <= 9; c++) {
                    if (c != a && c != b)
                        for(int d = 0; d <= 9; d++) {
                            if (d != a && d != b && d != c) {
                                int left1 = (100 * a + 10 * b + c);
                                int left2 = d;
                                int product = left1 * left2;
                                if(check(product, a, b, c, d)) {
                                    cout << left1 << "*" << left2 << "=" << product << endl;
                                }     
                                
                                left1 = (10 * a + b);
                                left2 = (10 * c + d);  
                                product = left1 * left2;
                                if(check(product, a, b, c, d)) {
                                    cout << left1 << "*" << left2 << "=" << product << endl;
                                }    
                                
                                left1 = a;
                                left2 = (100 * b + 10 * c + d);  
                                product = left1 * left2;
                                if(check(product, a, b, c, d)) {
                                    cout << left1 << "*" << left2 << "=" << product << endl;
                                }                             
                            }
                        }
                }
        }
    }
    
    cout << cnt << endl;
    return 0;
} 
