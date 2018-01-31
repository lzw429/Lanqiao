#include <iostream>

using namespace std;

int myStrcmp(const char *src,
             const char *dst) {
    int ret = 0;

    while ((ret = *(unsigned char *) src - *(unsigned char *) dst) == 0 && *dst)
        ++src, ++dst;

    if (ret < 0)
        ret = -1;
    else if (ret > 0)
        ret = 1;

    return (ret);
}

int main() {
    char s1[100], s2[100];
    cin.getline(s1, 100);
    cin.getline(s2, 100);
    cout << myStrcmp(s1, s2);
    return 0;
}
