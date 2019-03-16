//
// Created by syh on 19-3-16.
//

#include <stdio.h>
#include <string.h>

#define N 256

int f(const char *s1, const char *s2) {
    int a[N][N];
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j;

    memset(a, 0, sizeof(int) * N * N);
    int max = 0;
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                a[i][j] = a[i - 1][j - 1] + 1;  //填空
                if (a[i][j] > max) max = a[i][j];
            }
        }
    }

    return max;
}

int main() {
    printf("%d\n", f("abcdkkk", "baabcdadabc")); // 4
    printf("%d\n", f("bca", "dcdcabcbb")); // 2
    printf("%d\n", f("2143141432", "42332431224")); // 3
    return 0;
}