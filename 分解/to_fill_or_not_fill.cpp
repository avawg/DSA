#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

// 加油站有两个属性，油价，距离，按距离排序。
struct Station {
  double price, dist;
  bool operator<(const Station& s) const { return dist < s.dist; }
};

// 时间复杂度O(nlogn) 排序
int main() {
  double maxCap, distance, distAvg; // 分别表示油箱容量，终点距离，平均每升油行驶的距离
  int n; // 加油站数目
  Station stations[510];
  while (cin >> maxCap >> distance >> distAvg >> n) {
    for (int i = 0; i < n; ++i) cin >> stations[i].price >> stations[i].dist;

    stations[n].price = 0;  //将终点加油站油价设置为0, 确保在能到终点情况下,油无剩余
    stations[n].dist = distance;

    sort(stations, stations + n + 1);
    int i = 0;
    double curCap = 0, curCost = 0;
    while (i <= n) {
      if (i == n) { // 到达终点
        printf("%.2lf\n", curCost);
        break;
      }

      // 油加满也无法到下一站，输出最远距离
      if (stations[i].dist + distAvg * maxCap < stations[i + 1].dist) {
        printf("The maximum travel distance = %.2lf\n", stations[i].dist + distAvg * maxCap);
        break;
      }

      // 寻找当前站可达范围内，价格最便宜的加油站，没有则找到价格最低的加油站
      int mini = i + 1;
      double minPrice = stations[mini].price;
      for (int j = i + 1; j <= n && stations[i].dist + distAvg * maxCap >= stations[j].dist; ++j) {
        if (stations[j].price <= minPrice) {
          minPrice = stations[j].price;
          mini = j;
        }
        if (stations[mini].price <= stations[i].price) break; // 找到价格更低的加油站，退出
      }
      // 可达范围内存在比当前站价格低的加油站，则移动到该站
      if (stations[mini].price <= stations[i].price) { // 油够到该站
        if (stations[i].dist + distAvg * curCap >= stations[mini].dist)
          curCap -= (stations[mini].dist - stations[i].dist) / distAvg;
        else { // 油不够到该站
          curCost += stations[i].price * ((stations[mini].dist - stations[i].dist) / distAvg - curCap);
          curCap = 0;
        }
        i = mini;
      }
      // 可达范围内不存在比当前加油站价格低的加油站，直接加满油，移动到范围内价格最低的加油站
      else {
        curCost += stations[i].price * (maxCap - curCap);
        curCap = maxCap - (stations[mini].dist - stations[i].dist) / distAvg;
        i = mini;
      }
    }
  }
  return 0;
}