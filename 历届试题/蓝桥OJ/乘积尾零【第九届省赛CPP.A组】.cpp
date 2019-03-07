#include <iostream>
using namespace std;
int count_2 = 0, count_5 = 0; // 计算2和5的个数
int num_count = 0;

void count2(int num) {
  while (num % 2 == 0) {
    count_2++;
    num /= 2;
  }
}

void count5(int num) {
  while (num % 5 == 0) {
    count_5++;
    num /= 5;
  }
}

int main() {
  int t;
  while (scanf("%d", &t) != EOF) {
    num_count++;
    count2(t);
    count5(t);
  }
  printf("num_count: %d\ncount2: %d\ncount5: %d\n", num_count, count_2,
         count_5);
  return 0;
}
