#include <iostream>
using namespace std;

/**
* 利用异或运算交换
*/
int main() {
    int a = 100, b = 200;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b;
}