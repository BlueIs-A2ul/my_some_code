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







#### 问题与反思：



