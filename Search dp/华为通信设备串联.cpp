/**
 * 实验室有 2^k种设备，每种设备有一个功率参数，分别用0,1,2,3,......,2^(k - 1)表示，
 * 现需取出n个设备(可以是同种设备)，将他们两两连接形成一个环，相邻的两个设备间的功率参数XNOR不能为0，否则会爆炸；
 * 共有多少种连接方式不会爆炸
 */

 #include <iostream>
 using namespace std;

 int main() {
     int n, k;
     cin >> n >> k;
     int mod = 1e9 + 7, prod = 1;
     for (int i = 0; i < k; i++) {
         prod = prod * 2 % mod;
     }
     int prod2 = (prod - 2 + mod) % mod;
     int prod3 = (prod - 3 + mod) % mod;
     // 环状链表开头结尾设备不能相反 任选一种设备k，作为开头
     // 0 k结尾 1 ~k结尾 2其它结尾
     long dp[2][3] = {0, 0, 0, 1, 0, 0};
     for (int i = 2; i <= n; i++) {
         dp[i % 2][0] = (dp[(i + 1) % 2][0] + dp[(i + 1) % 2][2]) % mod;
         dp[i % 2][1] = (dp[(i + 1) % 2][1] + dp[(i + 1) % 2][2]) % mod;
         dp[i % 2][2] = ((dp[(i + 1) % 2][0] + dp[(i + 1) % 2][1]) * prod2 + dp[(i + 1) % 2][2] * prod3) % mod;
     }
     long ans = (dp[n % 2][0] + dp[n % 2][2]) * prod % mod;
     cout << (int) ans;
 }
