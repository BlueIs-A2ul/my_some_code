### 一：有边数限制的最短路



### 题目链接：[[853. 有边数限制的最短路 - AcWing题库](https://www.acwing.com/problem/content/855/)]



#### 题目描述：

给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， **边权可能为负数**。

请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 `impossible`。

注意：图中可能 **存在负权回路** 。



#### 输入描述

第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y的有向边，边长为 z。

点的编号为 1∼n。

#### 输出描述

输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。

如果不存在满足条件的路径，则输出 `impossible`。



#### 用例输入 1



```
3 3 1
1 2 1
2 3 1
1 3 3
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

const int N = 510, M = 10010;

struct Edge
{
    int a;
    int b;
    int w;
} e[M];

int dist[N];
int back[N];
int n, m, k;
int num = 0;

bool bellmanFord()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    Ir(i, 0, k)
    {
        memcpy(back, dist, sizeof(dist));
        Ir(j, 0, m)
        {
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], back[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)
        return false;
    num = dist[n];
    return true;
}

signed main()
{
    cin >> n >> m >> k;
    Ir(i, 0, m) cin >> e[i].a >> e[i].b >> e[i].w;
    if(!bellmanFord()) cout << "impossible" << endl;
    else  cout << num << endl;
    return 0;
}

```



### 解题思路：

在这里我们使用一个结构体来存储图，我们主要是利用一个`dist[b] = min(dist[b], back[a] + w)`的松弛操作，也就是对于一个结点，每次遍历都尝试通过当前边来更新终点的最短距离估计。如果通过当前边可以找到一个更短的路径，则更新该终点的距离值。

最后还要进行一次检测，如果说终点还可以找到更新距离的边，则说明具有负权回路，这样的结果是无意义的。

#### 问题与反思：

1) 比起dijkstra算法，bellman-ford算法的好处是可以处理存在负权边的情况，但与此同时，这个算法要求遍历性质的松弛操作，使得时间复杂度是`O(VE)`
2) 实现逻辑相比dijkstra算法更加简单和简洁。。

