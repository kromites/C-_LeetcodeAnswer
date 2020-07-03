/*
    题目：2. 两数相加
    链接：https://leetcode-cn.com/problems/add-two-numbers/
    时间：2020-6-16        
    BY Kromite

    解题技巧： 直接通过构造链表来实现链表加法
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* h = ans;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        int flag=0;
        int num=0;
        while(l1&&l2){
            num = l1->val+l2->val + flag;
            h->next = new ListNode(num%10);
            flag = num/10;
            l1=l1->next;
            l2=l2->next;
            h = h->next;
        }
        while(l1){
            num = l1->val+flag;
            h->next = new ListNode(num%10);
            flag = num/10;
            l1=l1->next;
            h = h->next;
        }
        while(l2){
            num = l2->val+flag;
            h->next = new ListNode(num%10);
            flag = num/10;
            l2=l2->next;
            h = h->next;
        }
        if(flag)
            h->next = new ListNode(flag);
        return ans->next;
    }
};