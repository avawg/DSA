/*
定义三元组 (a,b,c)（a,b,c 均为整数）的距离 D=|a−b|+|b−c|+|c−a|。
给定 3 个非空整数集合 S1,S2,S3，按升序分别存储在 3 个数组中。

请设计一个尽可能高效的算法，计算并输出所有可能的三元组 (a,b,c)（a∈S1,b∈S2,c∈S3）中的最小距离。
例如 S1={−1,0,9},S2={−25,−10,10,11},S3={2,9,17,30,41} 则最小距离为 2，相应的三元组为 (9,10,9)。

输入格式
    第一行包含三个整数 l,m,n，分别表示 S1,S2,S3 的长度。
    第二行包含 l 个整数，表示 S1 中的所有元素。
    第三行包含 m 个整数，表示 S2 中的所有元素。
    第四行包含 n 个整数，表示 S3 中的所有元素。
    以上三个数组中的元素都是按升序顺序给出的。

输出格式: 输出三元组的最小距离。
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // 读入数据
    int l, m, n;
    cin >> l >> m >> n;
    int s1[l], s2[m], s3[n];
    for (int i = 0; i < l; i++) {
        cin >> s1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> s2[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s3[i];
    }

    int minDist = ~(1 << 31);
    int i = 0, j = 0, k = 0;
    // 时间复杂度O(l + m + n)
    while (i < l && j < m && k < n) {
        int dist = abs(s1[i] - s2[j]) + abs(s1[i] - s3[k]) + abs(s2[j] - s3[k]);
        if (dist < minDist) {
            minDist = dist;
            if (minDist == 0) {
                cout << minDist;
                return 0;
            }
        }
        // 当固定最小元素时，剩余两个元素向右移动只会使距离增大，这些情况可以排除
        // 故将最小元素指针向右移动。
        if (s1[i] <= s2[j] && s1[i] <= s3[k]) {
            i++;
        } else if (s2[j] <= s1[i] && s2[j] <= s3[k]) {
            j++;
        } else {
            k++;
        }

    }
    cout << minDist;
    return 0;
}
