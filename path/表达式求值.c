#include <stdio.h>
#include <ctype.h>
// 输入为四则运算表达式，仅有数字、+、-、*、/、(、)组成，没有空格，要求求其值。
// 假设运算符结果都是整数。“/”结果也是整数。例3*6+4/2-123+(1*8-99/3)*4

// 时间复杂度O(n)
char cpeek() {
    char ans = getc(stdin);
    ungetc(ans, stdin);
    return ans;
}

int factorValue();
int termValue();
int expresionValue();

int main() {
    printf("%d", termValue());
    return 0;
}

int termValue() {   // factorValue + / - factorValue
    int result = factorValue();
    while (1) {
        char c = cpeek();
        if (c == '+') {
            getc(stdin);
            result += factorValue();
        } else if (c == '-') {
            getc(stdin);
            result -= factorValue();
        } else {
            break;
        }
    }
    return result;
}

int factorValue() {  // expresionValue * / / expresionValue
    int result = expresionValue();
    while (1) {
        char c = cpeek();
        if (c == '*') {
            getc(stdin);
            result *= expresionValue();
        } else if (c == '/') {
            getc(stdin);
            result /= expresionValue();
        } else {
            break;
        }
    }
    return result;
}

int expresionValue() { // 单独的一个数字，或（）内有termValue组成
    int result = 0;
    char c = cpeek();
    if (c == '('){  // 由括号组成
        getc(stdin);
        result = termValue();
        getc(stdin);
    } else {  // 由纯数字组成
        while (isdigit(cpeek())) {  // 将连续的字符转化成整数
            scanf("%c", &c);
            result = result * 10 + (c - '0');
        }
    }
    return result;
}