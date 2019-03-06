#include <iostream>
#include <cstring>
#define MAX_LEN 100010
using namespace std;
char h[MAX_LEN] = {};
char hexToBin[16][5] = {{'0', '0', '0', '0', '0'}, {'1', '0', '0', '0', '1'},
                        {'2', '0', '0', '1', '0'}, {'3', '0', '0', '1', '1'},
                        {'4', '0', '1', '0', '0'}, {'5', '0', '1', '0', '1'},
                        {'6', '0', '1', '1', '0'}, {'7', '0', '1', '1', '0'},
                        {'8', '1', '0', '0', '0'}, {'9', '1', '0', '0', '1'},
                        {'A', '1', '0', '1', '0'}, {'B', '1', '0', '1', '1'},
                        {'C', '1', '1', '0', '0'}, {'D', '1', '1', '0', '1'},
                        {'E', '1', '1', '1', '0'}, {'F', '1', '1', '1', '1'}};
void hexToOct(char h[]) {
  int b_i = 0;
  char b[4 * MAX_LEN] = {};
  // 将十六进制数存为二进制
  for (int i = 0; i< strlen(h); i++) {
    for (int j = 0; j < 16; j++) {
      if (hexToBin[j][0] == h[i]) {
        for (int k = 0; k <= 3; k++) {
          b[b_i++] = hexToBin[j][k];
        }
        break;
      }
    }
  }
  // 将二进制存为八进制
  for (int i = b_i; i > 0; i++) {
    cout << b[i];
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
  	memset(h, 0, sizeof(h));
    cin >> h;
    hexToOct(h);
    cout<<h; 
  }
  return 0;
}
