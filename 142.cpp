/*
    题目：142. 环形链表II
    链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/
    时间：2020-6-18        
    BY Kromite

    解题技巧： 可以使用哈希表存储节点，或者使用快慢指针。根据141快慢指针肯定会重逢，然后让指针在重逢点再遍历一次
              再构造一个初始指向head的指针，这样他们会在第一个点重逢。
    1--------A-----B--------2: 假设1为头，2为尾，由于快慢指针，则1-A和B-2的距离相同因此想要B-A则只需在构建一个1出的节点一起遍历即可。
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
        ListNode *detectCycle(ListNode *head){
            if(head==nullptr)
                return nullptr;
            bool flag = false;
            ListNode *p = head, *q =head;
            while(q->next && q->next->next){
                p = p->next;
                q = q->next->next;
                if(p==q)
                {
                    flag=true;
                    break;
                }
            }
            if(flag){
                ListNode *q1 = head;
                while(q1!=q){
                    q1 = q1->next;
                    q = q->next;
                }
                return q;
            }
            else
                return nullptr;
        }
};
