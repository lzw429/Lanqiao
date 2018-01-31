int gcd(int a, int b) {
    int g;
    if (!b)g = a;
    else g = gcd(b, a % b);
    return g;
}

ostream &operator<<(ostream &os, const zrf_Ratio &ratio) {
    // 输出最简分数
    int g = gcd(ratio.num, ratio.den);
    os << ratio.num / g << "/" << ratio.den / g;
    return os;
}

istream &operator>>(istream &is, zrf_Ratio &ratio) {
    is >> ratio.num >> ratio.den;
    return is;
}

bool operator==(const zrf_Ratio &a, const zrf_Ratio &b) {
    if (a.num * b.den == a.den * b.num)
        return true;
    return false;
}

bool operator<(const zrf_Ratio &a, const zrf_Ratio &b) {
    if (a.num * b.den < a.den * b.num)
        return true;
    return false;
}