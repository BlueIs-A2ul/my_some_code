#include <bits/stdc++.h>
#define int long long
#define Ir(i, a, b) for (int i = a; i < b; i++)
#define Ip(i, a, b) for (int i = a; i <= b; i++)
#define F(a, ch) for (auto a : ch)
#define DG(x) cout << #x << " = " << x << endl;

#define MAXN 100005
using namespace std;

int dp_fib[45];
int T, n;
bool flag = false;

void init()
{
    dp_fib[0] = 0;
    dp_fib[1] = 1;
    for (int i = 2; i < 45; i++)
        dp_fib[i] = dp_fib[i - 1] + dp_fib[i - 2];
}

struct fib_plus
{
    int fib_1;
    int fib_2;
    int fib_sum;
};

vector<fib_plus> fib_plus_arr(2500);

void creat_fib_plus()
{
    int cnt = 0;
    Ir(i, 0, 45)
    {
        Ir(j, 0, 45)
        {
            fib_plus_arr[cnt].fib_1 = dp_fib[i];
            fib_plus_arr[cnt].fib_2 = dp_fib[j];
            fib_plus_arr[cnt].fib_sum = dp_fib[i] + dp_fib[j];
            cnt++;
        }
    }
}

#include <iostream>
#include <vector>
#include <algorithm> // 引入算法库以使用sort

using namespace std;

void max_out(int a, int b, int c)
{
    vector<int> nums = {a, b, c};                   // 将三个数放入数组
    sort(nums.begin(), nums.end(), greater<int>()); // 降序排序

    cout << nums[0] << " " << nums[1] << " " << nums[2] << endl; // 输出结果
}

signed main()
{
    init();
    creat_fib_plus();
    unordered_set<int> uniques00;
    Ir(i, 0, 45)
    {
        if (uniques00.count(dp_fib[i]) == 0)
        {
            uniques00.insert(dp_fib[i]);
        }
    }
    unordered_set<int> uniques;
    Ir(i, 0, 2500)
    {
        if (uniques.count(fib_plus_arr[i].fib_sum) == 0)
        {
            uniques.insert(fib_plus_arr[i].fib_sum);
        }
    }
    cin >> T;
    while (T--)
    {
        flag = false;
        cin >> n;
        Ir(i, 0, 45)
        {
            if (uniques.count(n - dp_fib[i]))
            {
                int temp_fib = n - dp_fib[i];
                Ir(j, 0, 45)
                {
                    if (uniques00.count(temp_fib - dp_fib[j]))
                    {
                        flag = true;
                        max_out(dp_fib[i], dp_fib[j], n - dp_fib[i] - dp_fib[j]);
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << "-1" << endl;
    }
    return 0;
}
