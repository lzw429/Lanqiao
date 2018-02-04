/*
日期问题

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入
----
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)

输出
----
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。

样例输入
----
02/03/04

样例输出
----
2002-03-04
2004-02-03
2004-03-02

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
 */
#include <iostream>
#include <set>

using namespace std;

class Date {
public:
    int year;
    int month;
    int day;

    Date(int a, int b, int c) {
        this->year = a;
        this->month = b;
        this->day = c;
    }

    bool operator<(const Date &d) const {
        if (this->year != d.year)
            return this->year < d.year;
        else if (this->month != d.month)
            return this->month < d.month;
        else return this->day < d.day;
    }
};

set <Date> dateSet;

void push(int a, int b, int c) {
    if (a >= 60)
        a += 1900;
    else
        a += 2000;
    if (b > 12 || c > 31)return;
    bool leap = false;
    if (a % 4 == 0)
        leap = true;
    if (b == 2 && leap && c > 29)
        return;
    else if (b == 2 && !leap && c > 28)
        return;
    else if (b == 4 || b == 6 || b == 9 || b == 11)
        if (c > 30)return;
    Date date(a, b, c);
    dateSet.insert(date);
}


int main() {
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    push(a, b, c);
    push(c, a, b);
    push(c, b, a);
    for (set<Date>::iterator i = dateSet.begin(); i != dateSet.end(); ++i) {
       Date d=*i;
        printf("%d-%02d-%02d\n", d.year, d.month, d.day);
    }
    return 0;
}
