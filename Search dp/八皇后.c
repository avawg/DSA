#include <stdio.h>
#include <math.h>

const int N = 8;
const int MAXN = 100;

// 每一行只能放一个皇后，放第k行的皇后。k = 0,1,...7
// 时间复杂度 O(n^n) / O(n!)
void nqueen(int loc[], int k) {
    if (k == N) {
        for (int i = 0; i < N; ++i) {
            printf("%d", loc[i]);
        }
        printf("\n");
        return ;
    }
	// 尝试把第k行皇后放在第i列
    for (int i = 0; i < N; ++i) {
        int j;
        for (j = 0; j < k; ++j) {
			if(loc[j] == i || abs(j-k) == abs(loc[j]-i))
				break;  // 与第j行皇后冲突，第k行皇后不能放在第i列，退出
        }
        if (j == k) {
            loc[k] = i;
            nqueen(loc, k+1);
        }
    }
}

int main() {
    int loc[MAXN];
    nqueen(loc, 0);
    return 0;
}
