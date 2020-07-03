/*
    题目：141. 环形链表
    链接：https://leetcode-cn.com/problems/linked-list-cycle/
    时间：2020-6-18        
    BY Kromite

    解题技巧： 可以使用哈希表存储节点，或者使用快慢指针，快指针走两格，慢指针一格，最终肯定会重逢
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
        bool hasCycle(ListNode *head){
            if(head==nullptr)
                return false;
            ListNode *p = head, *q =head;
            while(q->next && q->next->next){
                p = p->next;
                q = q->next->next;
                if(p==q)
                    return true;
            }
            return false;
        }
};