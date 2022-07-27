#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int m, n;
    scanf("%d %d %d", &m, &n);
    int mat[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    }
    int sum[m + 1][n + 1];
    memset(sum, 0, sizeof(sum));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] + mat[i][j] - sum[i][j];
        }
    }
    int x1, y1, x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%d\n", sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 -1][y1 - 1]);
    return 0;
}