### 一：Hey！Vergil！



### 题目链接：[[Hey！Vergil！ - 虚动智能OJ](http://xdzn.club/problem/2331)]



#### 题目描述：

Dante终于走上树顶来到了老哥Vergil面前，他要取走Vergil的阎魔刀关闭魔界大门，但是Vergil告诉他这次我们不像小时候那样打架解决问题，来点不一样的。

Vergil说他把阎魔刀藏了起来，Dante必须解出下面这道编程题，老哥才会告诉藏在了哪里。

Vergil随机给Dante一个`单链表L：L0 -> L1 -> L2 -> ... -> Ln-1 -> Ln`，他要求Dante必须按照以下规则将链表重排，并交把结果交还给他

规则：`L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> .....`

Vergil认为从小只会打架，不像自己那么喜欢读书的Dante这次肯定会吃瘪

#### 输入描述

输入一个链表

#### 输出描述

输出根据规则重排后的链表。逗号使用英文逗号，末尾不空格不换行

#### 用例输入 1



```
4
50 66 83 67
```



#### 用例输出 1



```
50,67,66,83
```



### 解题代码：



```cpp
#include <iostream>
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *secondHalf = slow->next;
        slow->next = nullptr;

        secondHalf = reverseList(secondHalf);

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        ListNode *p1 = head, *p2 = secondHalf;

        while (p1 && p2)
        {
            tail->next = p1;
            p1 = p1->next;
            tail = tail->next;

            tail->next = p2;
            p2 = p2->next;
            tail = tail->next;
        }

        if (p1)
        {
            tail->next = p1;
        }
        else
        {
            tail->next = p2;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }

private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};


void printList(ListNode *head,int N)
{
    while (head && N--)
    {
        std::cout << head->val;
        if (N > 0)
            std::cout << ",";
        head = head->next;
    }
}


ListNode *createList(const std::vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    ListNode *head = new ListNode(nums[0]);
    ListNode *curr = head;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    Solution sol;
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> nums[i];
    }
    ListNode *head = createList(nums);

    ListNode *sortedList = sol.sortList(head);
    printList(sortedList,N);

    return 0;
}

```



### 解题思路：

这个链表重排涉及到一个从头从尾的交叉排列，所以可以想到要么每次找到尾结点，重新连接，再归为NULL，后重新找尾结点。要么先对后半部分进行重排，按顺序来交叉排列

#### 问题与反思：

1.对于直接在主程序里面输入一个链表的操作还是卡了蛮久，一直感觉不是很简洁

2.最开始对快慢指针找中间的长度讨论上有点问题，后面还是专门讨论了一下



