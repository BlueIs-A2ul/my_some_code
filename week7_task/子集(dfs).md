### 一：求子集



### 题目链接：[[78. 子集 - 力扣（LeetCode）](https://leetcode.cn/problems/subsets/description/?envType=problem-list-v2&envId=VgC3G1qe)]



#### 题目描述：

给你一个整数数组 `nums` ，数组中的元素 **互不相同** 。返回该数组所有可能的

子集（幂集）。

解集 **不能** 包含重复的子集。你可以按 **任意顺序** 返回解集。

#### 输入描述

给出这个整数数组



#### 输出描述

输出一个二维数组，每排代表一个子集



#### 用例输入 1



```
nums = [1,2,3]
```



#### 用例输出 1



```
[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```



### 解题代码：



```cpp
class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> current;
        backtrack(res, current, nums, 0); // 从索引 0 开始
        return res;
    }

private:
    void backtrack(std::vector<std::vector<int>> &res, std::vector<int> &current, const std::vector<int> &nums, int index)
    {
        res.push_back(current); // 添加当前子集到结果集中

        for (int i = index; i < nums.size(); ++i)
        {                                         // 从当前索引开始考虑元素
            current.push_back(nums[i]);           // 做选择
            backtrack(res, current, nums, i + 1); // 递归调用，考虑下一个元素
            current.pop_back();                   // 撤销选择
        }
    }
};
```



### 解题思路：

1.子集在某种意义上来说也算是特殊的组合了，我们在这里同样采取DFS的思路来解决这个问题

2.首先我们在这里由于函数需要输出的是一个vector二维数组，我们考虑重新定义一个函数来完成这个输出，其中`current`用来表示每一次输出产生的某一个`子集`，在每次完成后`res.push_back(current)`完成输入

3.在每次递归时我们在`for`循环中利用`int i = index`，来确保我们一定遍历到每一个元素

#### 问题与反思：

1.这个顺序安排很巧妙，拿用例来举例子，正好是在`res.push_back`了`[1][1,2][1,2,3]`以后来进行一个撤销操作。再加上索引的安排正好可以将每个子集都`push`进入`res`.

