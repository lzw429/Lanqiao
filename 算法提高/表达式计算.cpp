#include <iostream>
#include <stack>
#include <cstring> // strlen

using namespace std;
stack<int> num; // 数字栈
stack<char> op; // 运算符栈
char ch[150]; // 输入的表达式

int compute() // 根据op栈顶的运算符，取两个数字计算一次
{
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    if (op.top() == '-')
        return b - a;
    if (op.top() == '+')
        return a + b;
    if (op.top() == '*')
        return a * b;
    if (op.top() == '/')
        return b / a;
}

int main() {
    cin >> ch; // 将整个表达式读入ch字符数组
    int i = 0;
    while (i < strlen(ch)) {
        if (isdigit(ch[i])) { // 如果当前是数字
            int t = 0;
            while (i < strlen(ch) && isdigit(ch[i])) // 读取多位数字
            {
                t = 10 * t + (ch[i] - '0');
                i++;
            }
            num.push(t); // 入数字栈
        } else if (ch[i] == '(') // 左括号直接入栈
            op.push(ch[i++]);
        else if (ch[i] == '+' || ch[i] == '-') { // 加减一级运算
            if (op.empty() || op.top() == '(') { // 如果栈空或栈顶为左括号
                op.push(ch[i++]); // 直接入栈
            } else { // 否则先进行运算，再入栈
                int t = compute();
                num.push(t);
                op.pop();
                op.push(ch[i++]);
            }
        } else if (ch[i] == '*' || ch[i] == '/') { // 乘除二级运算
            if (op.empty() || op.top() == '(' || op.top() == '+' || op.top() == '-') {
                op.push(ch[i++]); // 直接入栈
            } else {
                int t = compute();
                num.push(t);
                op.pop();
                op.push(ch[i++]);
            }
        } else if (ch[i] == ')') {
            while (op.top() != '(') { // 栈顶如果不是左括号，一定是运算符
                int t = compute();
                num.push(t);
                op.pop();
            }
            op.pop(); // 括号内计算完后，左括号出栈
            i++;
        }
    }
    while (op.size() > 1) {
        int t = compute();
        num.push(t);
        op.pop();
    }
    cout << compute() << endl;
    return 0;
}
