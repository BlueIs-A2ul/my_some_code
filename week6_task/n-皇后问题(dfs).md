### 一：n-皇后问题



### 题目链接：[[843. n-皇后问题 - AcWing题库](https://www.acwing.com/problem/content/845/)]



#### 题目描述：

n−皇后问题是指将 n 个皇后放在 n×n 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

![1_597ec77c49-8-queens.png](https://cdn.acwing.com/media/article/image/2019/06/08/19_860e00c489-1_597ec77c49-8-queens.png)

现在给定整数 n，请你输出所有的满足条件的棋子摆法。



#### 输入描述

共一行，包含整数 n。

#### 输出描述

每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。

其中 `.` 表示某一个位置的方格状态为空，`Q` 表示某一个位置的方格上摆着皇后。

每个方案输出完成后，输出一个空行。

**注意：行末不能有多余空格。**

输出方案的顺序任意，只要不重复且没有遗漏即可。

数据范围：1~9

#### 用例输入 1



```
4
```



#### 用例输出 1



```cpp
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
```



### 解题代码：



```cpp
#include <iostream>
using namespace std;
int n;
char arr[10][10];
int  state[10] = { 0 };
bool check(int x, int y) {
    // 检查从左上到右下的对角线
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j] != '.') {
            return false;
        }
    }
    // 检查从左下到右上的对角线
    for (int i = x, j = y; i < n && j >= 0; i++, j--) {
        if (arr[i][j] != '.') {
            return false;
        }
    }
    // 检查从右上到左下的对角线
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
        if (arr[i][j] != '.') {
            return false;
        }
    }
    // 检查从右下到左上的对角线
    for (int i = x, j = y; i < n && j < n; i++, j++) {
        if (arr[i][j] != '.') {
            return false;
        }
    }
    return true;
}

void print(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] ;
            }
            cout << endl;
        }
        cout<<"\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!state[i]&&check(x,i)) {
            state[i] = 1;//state这里已经保证了同一列不会出现两个皇后
            arr[x][i] = 'Q';//这里的二维数组保证了行的唯一性
            //每次递归的 x+1 移向了下一行
            print(x + 1);
            //恢复棋盘
            state[i] = 0;
            arr[x][i] = '.';
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = '.';
        }
    }
    print(0);
    return 0;
}
```



### 解题思路：







#### 问题与反思：



