### 一：Prim算法求最小生成树



### 题目链接：[[858. Prim算法求最小生成树 - AcWing题库](https://www.acwing.com/problem/content/860/)]



#### 题目描述：

给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

`由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。`

#### 输入描述

第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

#### 输出描述

共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`

#### 用例输入 1



```
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
```



#### 用例输出 1



```
6
```



### 解题代码：



```cpp
#include <bits/stdc++.h>
// #define int long long
#define Ir(i, a, b) for (int i = a; i < b; i++)
#define Ip(i, a, b) for (int i = a; i <= b; i++)
#define F(a, ch) for (auto a : ch)
#define DG(x) cout << #x << " = " << x << endl;

#define MAXN 100005
using namespace std;

int n, m;
int gra[MAXN][MAXN];
int dist[MAXN];
bool st[MAXN];
int pre[MAXN];

void prim()
{
    memset(dist, 0x3f, sizeof(dist));
    int res = 0;
    dist[1] = 0;
    Ir(i, 0, n)
    {
        int t = -1;
        Ip(j, 1, n)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }

        if (dist[t] == 0x3f)
        {
            cout << "impossible\n";
            return;
        }

        st[t] = true;
        res += dist[t];
        Ip(j, 1, n)
        {
            if (dist[j] > gra[t][j] && !st[j])
            {
                dist[j] = gra[t][j];
                pre[j] = t;
            }
        }
    }

    cout << res << endl;
    return;
}

signed main()
{
    memset(gra, 0x3f, sizeof(gra));
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        gra[a][b] = gra[b][a] = min(gra[a][b], w);
    }

    prim();
    return 0;
}
```



### 解题思路：

1.在某种程度上来说`prim算法`和`dijkstra算法`具有一定的类似性,都有一个类似的通过遍历来找到最短距离的过程，只不过这个过程中，`dijkstra算法`寻找的是距离当源点的最近的点，而`prim`算法寻找的是距离当前的块最近的点。而且由于图的性质不同，这里存储的方式也不同，`dijkstra算法`用的是数组实现邻接表来存储，而`prim算法`作为稠密图使用的是二维数组的邻接矩阵。

2.

```cpp
Ip(j, 1, n){
    if (!st[j] && (t == -1 || dist[j] < dist[t]))
     t = j;}
```

在这个部分实现的就是寻找距离最短的点，并且在这里我们有一个类似贪心的思路，因为我们必定会对每个点进行遍历，因此只要我们对于每个点都进行找到至少一条最短路，那么在遍历完成以后，这一定是一个连通图。

#### 问题与反思：

1) 和`dijkstra算法`相似的`prim算法`同样可以使用优先队列，即最小堆的方法来对时间复杂度进行优化

