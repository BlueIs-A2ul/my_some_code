### 一：二叉树的最大深度



### 题目链接：[[104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)]



#### 题目描述：

给定一个二叉树 `root` ，返回其最大深度。

二叉树的 **最大深度** 是指从根节点到最远叶子节点的最长路径上的节点数。

#### 输入描述





#### 输出描述





#### 用例输入 1

<img src="https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg" alt="img" style="zoom: 67%;" />

```
root = [3,9,20,null,null,15,7]
```



#### 用例输出 1



```
3
```



### 解题代码：



```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->right) , maxDepth(root->left))+1;
    }
};
```



### 解题思路：







#### 问题与反思：



