/*
    题目：234. 回文链表
    链接：https://leetcode-cn.com/problems/palindrome-linked-list/
    时间：2020-6-19     
    BY Kromite

    解题技巧： 快慢指针找到中间的结点， 再将后面的结点反转，最后遍历两个拆分链表看是否相等；
*/

class Solution{
    private:
        struct ListNode
        {
            int val;
            ListNode* next;
            ListNode(int x): val(x), next(nullptr) {}
        };
    public:
    // 迭代方法，反转链表 见206.cpp
        ListNode* reverseList(ListNode* head){
            if(head==nullptr)   return nullptr;
            ListNode *pre = nullptr;
            ListNode *p = head;
            while(p){
                ListNode *temp = p->next;
                p->next = pre;
                pre = p;
                p = p->next;
            }
            return pre;
        }
        bool isPalindrome(ListNode* head) {
    // 1. 快慢指针，找到中间结点
            ListNode *slow= head, *fast = head;
            if(head==nullptr)  return true;
            while(fast&&fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
    // 2. 调用reverse反转后面的链表
            ListNode *pre = reverseList(slow);
    // 3. 逐个判断是否相同 
            while(pre&&head){
                if(pre->val!=head->val){
                    return false;
                }
                head = head->next;
                pre = pre->next;
            }
            return true;

        }
}；