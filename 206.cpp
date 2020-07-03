/*
    题目：206. 反转链表
    链接：https://leetcode-cn.com/problems/reverse-linked-list/
    时间：2020-6-19     
    BY Kromite

    解题技巧： 这道题目很经典！ 一定要把递归和迭代两种方法都掌握！
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
    // 1. 迭代方法， 就是不停地将结点的next翻转，原来是p->q, 要变成p<-q;
        ListNode* reverseList1(ListNode* head){
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
    // 2. 递归方法，递归的意思：我子节点下的所有节点都已经反转好了，现在就剩我和我的子节点 没有完成最后的反转了，所以反转一下我和我的子节点。
    // 不妨假设链表为1，2，3，4，5。按照递归，当执行reverseList（5）的时候返回了5这个节点，
    // reverseList(4)中的p就是5这个节点，我们看看reverseList（4）接下来执行完之后，5->next = 4, 4->next = null。
    // 这时候返回了p这个节点，也就是链表5->4->null，接下来执行reverseList（3），代码解析为4->next = 3,3->next = null，
    // 这个时候p就变成了，5->4->3->null, reverseList(2), reverseList(1)依次类推，p就是:5->4->3->2->1->null
        ListNode* reverseList2(ListNode* head){
            if(head==nullptr||head->next==nullptr)  return head;
            ListNode *p = reverseList2(head->next);
            head->next->next = head;
            head->next = nullptr;
            return p;
        }
}；