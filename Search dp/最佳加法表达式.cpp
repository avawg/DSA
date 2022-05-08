/**
    描述
        给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。
        例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36
    输入
        有不超过15组数据
        每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
        第二行是若干个数字。数字总数n不超过50,且 m <= n-1
    输出
        对每组数据，输出最小加法表达式的值
    样例输入
        2
        123456
        1
        123456
        4
        12345
    样例输出
        102
        579
        15
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b);
int compare(string a, string b);

string dp[51][50];
int main() {
    string s;
    int m;
    while (cin >> m >> s) {
        int n = s.length();
        // dp[i][k] 在前i个数字中插入j个+
        for (int i = 1; i <= n; i++) {
            dp[i][0] = s.substr(0, i);
        }
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= min(i - 1, m); k++) {
                dp[i][k] = dp[i][0];
                // 考虑最后一个’+‘的插入位置
                for (int l = k; l < i; l++) {
                    string sum = add(dp[l][k-1], s.substr(l, i - l));
                    if (compare(sum, dp[i][k]) < 0) {
                        dp[i][k] = sum;
                    }
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}

// 字符串模拟大整数相加
string add(string a, string b) {
    // 去除前导0
    int n = b.length(), i = 0, j = 0;
    while (i < n && b[i] == '0') {
        i++;
    }
    b = i == n ? "0" : b.substr(i);
    string s;
    i = a.length() - 1;
    j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry != 0) {
        int x = i >= 0 ? a[i] - '0' : 0;
        int y = j >= 0 ? b[j] - '0' : 0;
        int sum = x + y + carry;
        s += (char) ((sum % 10) + '0');
        carry = sum / 10;
		--i;
		--j;
    }
    reverse(s.begin(), s.end());
    return s;
}

// 字符串模拟大整数比较
int compare(string a, string b) {
    if (a.length() < b.length()) {
        return -1;
    }
    if (a.length() > b.length()) {
        return 1;
    }
    return a.compare(b);
}
