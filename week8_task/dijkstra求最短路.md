### 一：dijkstra求最短路



### 题目链接：[[849. Dijkstra求最短路 I - AcWing题库](https://www.acwing.com/problem/content/851/)]



#### 题目描述：

给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

#### 输入描述

第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

#### 输出描述

输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

#### 用例输入 1



```
3 3
1 2 2
2 3 1
1 3 4
```



#### 用例输出 1



```
3
```



### 解题代码：



```cpp
#include <bits/stdc++.h>
#define int long long
#define Ir(i, a, b) for (int i = a; i < b; i++)
#define Ip(i, a, b) for (int i = a; i <= b; i++)
#define F(a, ch) for (auto a : ch)
#define DG(x) cout << #x << " = " << x << endl;

#define MAXN 100005
using namespace std;

const int N = 510, M = 100010;

int h[N], e[M], ne[M], w[M], idx; // 邻接表存储图
int state[N];                     // state 记录是否找到了源点到该节点的最短距离
int dist[N];                      // dist 数组保存源点到其余各个节点的距离
int n, m;                         // 图的节点个数和边数

void add(int a, int b, int c) // 插入边
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist)); // dist 数组的各个元素为无穷大
    dist[1] = 0;                      // 源点到源点的距离为置为 0
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        Ir(j, 1, n) // 遍历所有节点，找到距离源点最近的点 t
        {
            if (!state[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }

        state[t] = 1; // state[i] 置为 1。

        for (int j = h[t]; j != -1; j = ne[j]) // 遍历 t 所有可以到达的节点 i
        {
            int i = e[j];
            dist[i] = min(dist[i], dist[t] + w[j]); // 更新 dist[j]
        }
    }
}

signed main()
{
    memset(h, -1, sizeof(h)); // 邻接表初始化

    cin >> n >> m;
    while (m--) // 读入 m 条边
    {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }

    Dijkstra();
    (dist[n] == 0x3f) ? cout << "-1" : cout << dist[n]; // 输出结果
    return 0;
}

```



### 解题思路：

1.在这里我们首先还是用邻接表的方法来存储图，`dist` 数组保存源点到其余各个节点的距离，`state` 记录是否找到了源点到该节点的最短距离

2.对于这个问题，我们采用`dijkstra`算法的内容，首先进行遍历，找到距离源点最近的点`t`，对对应的`state元素`进行标记表示已经找到了`最短距离`。

3.然后是`for循环遍历的t的出边`，我们通过`ne[]`的链式结构，来对所有`t`的出边做处理，如果可以更小就要更新`dist[i]`的值，这样一直重复的遍历，直到所有结点都进行了相同操作。

#### 问题与反思：

1.我们一开始貌似没有确定`t`和源点的关系，我们是怎么保证`t`一定是与源点相连的呢？这与我们的输入顺序有关系，我们在这里要先输入源点的对应，这样才能对应到源点

2.这个并不是最优的解法，可以发现这个算法的主要耗时在寻找一个使`dist[j] < dist[t]`成立的最小的`j`，对于这种寻找我们可以采用优先队列，即是最小堆的方法降低时间复杂度。

