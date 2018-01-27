#include <iostream>

using namespace std;

class Complex {
public:
    double real;
    double imaginary;

    Complex(double r, double i) {
        this->real = r;
        this->imaginary = i;
    }
};

Complex *add(Complex *c1, Complex *c2) {
    return new Complex(c1->real + c2->real, c1->imaginary + c2->imaginary);
}

Complex *sub(Complex *c1, Complex *c2) {
    return new Complex(c1->real - c2->real, c1->imaginary - c2->imaginary);
}

Complex *multiply(Complex *c1, Complex *c2) {
    double a = c1->real, b = c1->imaginary, c = c2->real, d = c2->imaginary;
    return new Complex(a * c - b * d, b * c + a * d);
}

Complex *divide(Complex *c1, Complex *c2) {
    double a = c1->real, b = c1->imaginary, c = c2->real, d = c2->imaginary;
    return new Complex((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d));
}

int main() {
    char operation;
    double r1, r2, i1, i2;
    cin >> operation >> r1 >> i1 >> r2 >> i2;
    Complex *c1 = new Complex(r1, i1);
    Complex *c2 = new Complex(r2, i2);
    Complex *res;
    switch (operation) {
        case '+':
            res = add(c1, c2);
            break;
        case '-':
            res = sub(c1, c2);
            break;
        case '*':
            res = multiply(c1, c2);
            break;
        case '/':
            res = divide(c1, c2);
            break;
        default:
            break;
    }
    printf("%.2f+%.2fi", res->real, res->imaginary);
    return 0;
}
