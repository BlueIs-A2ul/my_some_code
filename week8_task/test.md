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

int main()
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

1.首先对于一个图我们需要明确存储方式，在这里我们的存储方式选取的是数组实现的邻接表，因为对于某一个点我们需要去遍历与它的出度，在这里我们通过`j=ne[j]`的方式在for循环中，去遍历每一条出度。

2.然后这个算法的思路，我们先会创建一个`dist[]`数组，这个数组用来表示，从源点到第i个点的最短路径，也就是说在这里i作为索引，`dist[i]`的值即作为最短路径，然后再创建一个`state[]`数组，在这里用来表示，这条路径是否被途径过：

1) 首先我们认为源点到源点的距离是为0的。
2) 之后，我们先遍历找到一个距离源点最近的点`t`（这里我们在`if`中控制了，等下会使用的`t`一定是未被使用过的）
3) 确定了t以后，我们对于t的所有出度做这样处理，就可以算出对于`t`所能到达的所有`i`结点的`dist[i]`做计算

由此求出最小路径

#### 问题与反思：

1) 看似好像我们在最开始的遍历中没有对结点j和源点是否相连进行判断，但这有影响吗？实际是没有的这是邻接表的链式结构所决定的，我们存储的源点一定是一开始就被遍历到的，所以点一定和源点相连
2) 这个是最基本的模板，但是存在着优化的空间，因为这里的主要耗时在于从`dist[]`数组中选出，没有确定最短路径中的距离源点最近的点t。所以为了找到这个最小距离，我们可以采用优先队列（即最小堆）的办法来寻找这个最小的t。

