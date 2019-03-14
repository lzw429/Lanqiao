//
// Created by syh on 19-3-14.
//

#include <stdio.h>

void f(int x) {
    int i;
    for (i = 0; i < 32; i++) printf("%d", (x >> (31 - i)) & 1);
    printf("   ");

    //x = _______________________;
    x = x & (x + 1);

    for (i = 0; i < 32; i++) printf("%d", (x >> (31 - i)) & 1);
    printf("\n");
}

int main() {
    f(103); // binary: 1100111
    f(12); // binary: 1100
    return 0;
}