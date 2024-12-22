### 一：kmp字符串



### 题目链接：[[831. KMP字符串 - AcWing题库](https://www.acwing.com/problem/content/description/833/)]



#### 题目描述：

给定一个字符串 S，以及一个模式串P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模式串 P 在字符串 S 中多次作为子串出现。

求出模式串 P 在字符串 S 中所有出现的位置的起始下标。

#### 输入描述

第一行输入整数 N，表示字符串 P 的长度。

第二行输入字符串 P。

第三行输入整数 M，表示字符串 S 的长度。

第四行输入字符串 S。

#### 输出描述

共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。

#### 用例输入 1



```
3
aba
5
ababa
```



#### 用例输出 1



```
0 2
```



### 解题代码：



```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> next0;

void build_next(const string &s)
{
    int n = s.length();
    next0.resize(n);
    next0[0] = -1;
    int j = -1;
    for (int i = 1; i < n; i++)
    {
        while (j >= 0 && s[i] != s[j + 1])
            j = next0[j];

        if (s[i] == s[j + 1])
            j++;

        next0[i] = j;
    }
}

bool kmp(const string &s, const string &t)
{
    int m = t.length();
    if (m == 0)
        return true; // 如果目标字符串为空，直接返回真

    build_next(t);
    int j = -1;

    for (int i = 0; i < s.length(); i++)
    {
        while (j >= 0 && s[i] != t[j + 1])
            j = next0[j];

        if (s[i] == t[j + 1])
            j++;

        if (j == m - 1)
            return true; // 找到匹配
    }
    return false; // 未找到匹配
}

int main()
{
    string s, t;
	cin >> s >> t;
    if (kmp(s, t))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

```



### 解题思路：

1) kmp的算法关键避免了直接重复的大量遍历，而是在类似于双指针的情况下对`j`进行适当的回溯，而`i`只需要往前走即可，在对于`i`的这种处理，我们把时间复杂度由`O(M*N)`降到了`O(N)`

2) 在这里主要用到了`next[]`数组，在这里我们先暂且不管这个数组如何产生，只需要知道有两种情况：

    1.目标串是匹配的 `i++ ; j++`

    2.目标串是不匹配的 `j=next[j]`

    在这样的循环一直到`i`遍历完全整个字符串

3) 那么重点就是如何构建`next[]`数组，实际上是一个可以叫最长前后缀的数组，如果前后缀是相同的就取最大的，如果不同，就取对应位置的`已经有的next[]`重复上述操作，直至遍历完成。（~~印度老哥将其称为一个小技巧~~）

#### 问题与反思：

1.可能出现Segment Fault的段错误，中间对于数组的调用要注意。

