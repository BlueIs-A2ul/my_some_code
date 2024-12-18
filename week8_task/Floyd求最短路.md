### 一：Floyd求最短路



### 题目链接：[[854. Floyd求最短路 - AcWing题库](https://www.acwing.com/problem/content/description/856/)]



#### 题目描述：

给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定 k 个询问，每个询问包含两个整数 x 和 y，表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 `impossible`。

数据保证图中不存在负权回路。

#### 输入描述

第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。

#### 输出描述

共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 `impossible`。

#### 用例输入 1



```
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
```



#### 用例输出 1



```
impossible
1
```



### 解题代码：



```cpp
#include <bits/stdc++.h>
// #define int long long
#define Ir(i, a, b) for (int i = a; i < b; i++)
#define Ip(i, a, b) for (int i = a; i <= b; i++)
#define F(a, ch) for (auto a : ch)
#define DG(x) cout << #x << " = " << x << endl;

#define MAXN 1000050
using namespace std;

const int N = 300;
const int M = 2e+10, INF = 1e+9;

int n, m, k;
int a, b, c;
int dis[300][300];

void floyd()
{
    Ip(k, 1, n) Ip(i, 1, n) Ip(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
signed main()
{
    cin >> n >> m >> k;
    Ip(i, 1, n) Ip(j, 1, n) dis[i][j] = (i == j) ? 0 : INF;
    while (m--)
    {
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
    }
    floyd();
    while (k--)
    {
        cin >> a >> b;
        (dis[a][b] > INF / 2) ? cout << "impossible" : cout << dis[a][b] << endl;
    }
    return 0;
}

```



### 解题思路：

1.这个算法的基本思路是考虑两个端点和一个中转点，如果对于这两个端点`i`和`j`，通过中转点`k`，距离比本身的`dist[i] [j]`更小，那么就更新这个距离。

2.这个在算法实现上难度较低，实际就是把所有三个点的组合全部试一遍，最后得到最优的结果

#### 问题与反思：

1.实现简单，可以处理负权路(不能是负权回路)，算是`floyd算法`的特点，但是与此同时的问题是，时间复杂度到`O(n^3)`，在顶点较多的情况下，可能是容易超时的。

