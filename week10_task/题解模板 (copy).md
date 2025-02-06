### 一：快速幂

### 题目链接：[[875. 快速幂 - AcWing题库](https://www.acwing.com/problem/content/877/)]



#### 题目描述：

$$
给定n组\space a_i,b_i,p_i,对于每组数据，求出a_{i}^{b_i}mod\space p_i的值
$$



#### 输入描述

第一行包含整数 n。

接下来 n 行，每行包含三个整数ai,bi,pi

#### 输出描述

$$
对于每组数据，输出一个结果，表示 a_{i}^{b_i}mod\space p_i
 的值。

每个结果占一行。
$$

#### 用例输入 1



```
2
3 2 5
4 3 9
```



#### 用例输出 1



```
4
1
```



### 解题代码：



```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;

ll quick_pow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        ll n, k, m;
        cin >> n >> k >> m;
        ll ans = quick_pow(n,k, m);
        cout << ans << endl;
    }
    return 0;
}
```



### 解题思路：

1) 快速幂的主要核心就是自乘，它对比起`pow`函数的优势不在于计算的速度，而是可以在底数和质数都极大的情况下，一样完成计算的目的，尤其是在这个题目的求模的运算当中。
2) 自乘又是怎么实现的呢？从简单的角度来说类似于二进制算法，如下

$$
a^{13} = a^{(1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 1 \times 2^0)} = (a^8) \times (a^0) \times (a^2) \times (a^1) = a^8 \times a^2 \times a^1
$$

也就是说我们在这里将`13`转换成二进制的`1011`，那么指数就相应的变成了对应的次方。

3) 自乘实现之后还涉及到取模运算，我们不能再计算的最后再来取模，否则一样会数据溢出导致错误，所以我们要一边自乘一边取模，实现在代码就是`res = (res * a) % mod`

#### 问题与反思：

1) 取模涉及到`mod`的一些特性：`(a * b) % mod = ((a % mod) * (b % mod)) % mod`，这允许我们在进行加法和乘法运算时，分别对操作数取模，然后再对结果进行取模，从而得到与直接对完整结果取模相同的结果。
2) 并且我们的每次计算都使用幂的二进制来分解连乘，保证了这个过程的正确

