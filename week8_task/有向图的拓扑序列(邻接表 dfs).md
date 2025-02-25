### 一：有向图的拓扑序列



### 题目链接：[[848. 有向图的拓扑序列 - AcWing题库](https://www.acwing.com/problem/content/description/850/)]



#### 题目描述：

给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。

若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在  y之前，则称 A 是该图的一个拓扑序列。

#### 输入描述

第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

#### 输出描述

共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 −1。

#### 用例输入 1



```
3 3
1 2
2 3
1 3
```



#### 用例输出 1



```
1 2 3
```



### 解题代码：



```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int e[N], ne[N], idx;//邻接表存储图
int h[N];
int q[N], hh = 0, tt = -1;//队列保存入度为0的点，也就是能够输出的点，
int n, m;//保存图的点数和边数
int d[N];////保存各个点的入度

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    for(int i = 1; i <= n; i++){//遍历一遍顶点的入度。
        if(d[i] == 0)//如果入度为 0, 则可以入队列
            q[++tt] = i;
    }
    while(tt >= hh){//循环处理队列中点的
        int a = q[hh++];
        for(int i = h[a]; i != -1; i = ne[i]){//循环删除 a 发出的边
            int b = e[i];//a 有一条边指向b
            d[b]--;//删除边后，b的入度减1
            if(d[b] == 0)//如果b的入度减为 0,则 b 可以输出，入队列
                q[++tt] = b;
        }
    }
    if(tt == n - 1){//如果队列中的点的个数与图中点的个数相同，则可以进行拓扑排序
        for(int i = 0; i < n; i++){//队列中保存了所有入度为0的点，依次输出
            cout << q[i] << " ";
        }
    }
    else//如果队列中的点的个数与图中点的个数不相同，则可以进行拓扑排序
        cout << -1;//输出-1，代表错误
}


int main(){
    cin >> n >> m;//保存点的个数和边的个数
    memset(h, -1, sizeof h);//初始化邻接矩阵
    while (m -- ){//依次读入边
        int a, b;
        cin >> a >> b;
        d[b]++;//顶点b的入度+1
        add(a, b);
    }
    topsort();//进行拓扑排序
    return 0;
}
```



### 解题思路：

1.邻接表的数组实现，

```cpp
const int N = 100010;
int h[N];
int e[N], ne[N], idx;//邻接表存储图
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
```

1) `h[]`代表的是头指针数组，对于每个节点a，`h[a]`存储以节点a为起点的第一条边的索引`(如果h[a]的值是-1，则表示节点a没有连接的边，这里指他是一个孤立的节点，或者当前没有以他为起点的边)`
2) `e[]`这是用以存储边的终点的数组，对于每条边，`e[idx]`存储这条边指向的终点节点
3) `ne[]`用以存储下一条边的数组，对于每一条边，`ne[i]`存储以当前节点为起点，在当前边以后的下一条边的索引，如果`ne[i]`的值是-1，则表示为`null`，这个数组可以用于邻接表的链表实现，让我们可以从任何节点开始。遍历所有从该节点出发的边
4) `idx`是一个全局索引，可以用来保证每条边的索引都是唯一的
5) 另外这里我们还有一个数组`d[]`用来记录顶点的入度，原因在后面提及

2.显然对于题目来说，只要是`入度为0`的点，均可以放在序列的最前面`(因为他们不出现在任意一个组合(x,y)的前面一个数 )`，所以我们利用`d[]`记录入度数量，在输入完成后，先遍历入度为0的节点，进入队列

3.在这里因为`ne[]`的`链表性质`，我们可以利用它来遍历一个图中的所有的边，并且由2.我们可以知道，如果入度为0，那么则可以入队，因为对于一个有向无环图，一定存在至少一个入度为0的点。

#### 问题与反思：

1.`ne[]`是链式储存，我们可以利用它来遍历所有的边，直到`ne[i]=-1`

2.结合DFS，有一个复合的循环

