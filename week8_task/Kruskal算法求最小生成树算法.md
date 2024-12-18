### 一：Kruskal算法求最小生成树算法



### 题目链接：[[859. Kruskal算法求最小生成树 - AcWing题库](https://www.acwing.com/problem/content/861/)]



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
#define int long long
#define Ir(i, a, b) for (int i = a; i < b; i++)
#define Ip(i, a, b) for (int i = a; i <= b; i++)
#define F(a, ch) for (auto a : ch)
#define DG(x) cout << #x << " = " << x << endl;

#define MAXN 1000050
using namespace std;

int p[MAXN];
int n, m;
int res = 0;
int cnt = 0;

struct Edge
{
    int a;
    int b;
    int w;
    bool operator<(const Edge &e) const
    {
        return w < e.w;
    }
} ed[MAXN];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void kruskal()
{
    Ip(i, 1, m)
    {
        int pa = find(p[ed[i].a]), pb = find(p[ed[i].b]);
        if (pa != pb)
        {
            p[pb] = pa;
            res += ed[i].w;
            cnt++;
        }
    }
}
signed main()
{
    cin >> n >> m;
    Ip(i, 1, n) p[i] = i;
    Ip(i, 1, m)
    {
        cin >> ed[i].a >> ed[i].b >> ed[i].w;
    }
    sort(ed + 1, ed + m + 1);
    kruskal();
    (cnt < n - 1) ? cout << "impossible" : cout << res << endl;
    return 0;
}

```



### 解题思路：

1.`kruskal算法`是一种带有`贪心思路`的算法，我们为了求得最小生成树，在直觉上来说肯定希望每条边的权值都是最小的，所以这个算法也是这样，我们首先将所有的边按照权值来进行排序，并按照次序做一下判断：如果不组成回路，这条边加入连通块，反之舍去。直到具有n个顶点的联通网筛选出n-1条边（我们已经保证了之前的选择不会产生回路）。

2.那么重点就转移到了我们如何来判断会不会产生回路这个事情上面，在这里我们采用并查集的方法，具体模板可见主文件夹。

#### 问题与反思：

1.我们在这里利用一个并查集的思路，把连通块的点作为作为一个集合来看，如果作为端点的两个点都在集合里面了，证明这是一个回路了。

