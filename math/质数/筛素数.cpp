#include <iostream>
using namespace std;

const int N = 1000010;
int p[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) p[i] = true;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (p[i]) { // 没有被[2, i - 1]之间的质数筛掉
            for (int j = i * i; j <= n; j += i) {
                p[j] = false;
            }
            cnt++;
        }
    }
    cout << cnt;
}

```
// 线性筛法 O(n)
#include <iostream>
using namespace std;

const int N = 1000010;
int p[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) p[i] = true;
    int cnt = 0;
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (p[i]) primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j++) {
            p[primes[j] * i] = false;
            if (i % primes[j] == 0) break;
        }
    }
    cout << primes.size();
}


```