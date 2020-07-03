/*
    题目：160. 相交链表
    链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
    时间：2020-6-18        
    BY Kromite

    解题技巧： 先用遍历把A,B两个链表的长度求出来，然后长的采取截断，当长度相同时开始同时遍历两链表；
                当PA=PB且PA不指向空时则相交，否则无交点
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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *pa = headA, *pb = headB;
            int a=0;
            while(pa){
                pa = pa->next;
                a++;
            }
            while(pb){
                pb = pb->next;
                a--;
            }
            ListNode *pa2 = headA, *pb2 = headB; 
            while(a>0){
                pa2 =pa2->next;
                a--;
            }
            while(a<0){
                pb2 = pb2->next;
                a++;
            }
            while(pa2&&pb2&&pa2!=pb2){
                pa2 = pa2->next;
                pb2 = pb2->next;
            }
            if(pa2&&pb2)
                return pa2;
            else
                return nullptr;
        }
    
}；