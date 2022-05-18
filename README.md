数据结构与算法学习与idea记录

#### 数据结构：
	存储数据集合,方便查询、增加、删除、修改操作
##### list：
	array、linkedList、stack、queue
##### 树：
	二叉排序树(有序集合treeSet),priorityQueue,树状数组,Trie(store string)
##### HashSet:
	hash function + array
##### Integer
```
较小的数据集合可考虑用int整数表示(如‘a' - 'z'字母集合)，位运算代替增删改查操作
```

#### 算法：
##### 问题转化：
```
对立：最小删除 --> 最多添加选择
a -> b ==> b反方向变换到a
差分：[a，b] --> <= b - <= a
降维：矩阵 -> 数组
```
##### 枚举、搜索、dp
```
**搜索**尽可能朝目标靠近，减小不必要的状态搜索，bidirectional bfs; 二分搜索; 将n个数分为k份，让每份的和的最大值最小，搜索时优先使k份平均
```
##### 出发点：
```
最小最大值 (排序)
连续子数组：终点，差分枚举所有子数组
非连续子数组：第i个数作为终点
背包：第i个数选择与否
子区间: [0, i]
找不变量，固定值
```
##### 分治
```
缩小问题规模, 减半
```
##### 递归、贪心
