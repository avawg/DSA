#include <stdio.h>
#include <stdlib.h>

/**
 * 逆波兰表达式是一种把运算符前置的算法表达式，它优点是运算符之间不必有优先级关系，
 * 也不必用括号改变运算次序。
 * 输入：输入为一行，其中运算符和运算数之间用空格分割，运算数是表达式。
*/

// 时间复杂度O(n)
double exp() {
    char s[10];
    scanf("%s", s);
    switch (s[0]) {
    case '+':   return exp() + exp();
    case '-':   return exp() - exp();
    case '*':   return exp() * exp();
    case '/':   return exp() / exp();
    default:    return atof(s);
    }
}

int main() {
    printf("%lf\n", exp());
    return 0;
}
