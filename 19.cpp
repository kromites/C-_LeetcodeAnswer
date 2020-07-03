/*
    题目：19. 删除链表的倒数第N个节点
    链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
    时间：2020-6-17        
    BY Kromite

    解题技巧： 此题不难 一步一步来即可
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
        ListNode* removeNthFromEnd(ListNode* head, int n){
            ListNode *p = head, *q = head;
            int i=0;
            while(i<n){
                i++;
                q = q->next;
            }
            // 如果q==nullptr,那么说明删除的是第一个节点，因此可以直接返回head->next;
            if(!q)
                return head->next;
            // 如果q存在， 则返回p和q同时遍历，当q->next==nullptr时，p->next就是要删除的点。
            while(q->next){
                q = q->next;
                p = p->next;
            }
            p->next = p->next->next;
            return head;
        }
};