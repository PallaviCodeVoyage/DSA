/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr)
        {
            return head;
        }

        ListNode*small=new ListNode();
        ListNode*big=new ListNode();
        ListNode*curr=head;
        ListNode*s,*b;
        s=small;
        b=big;
        while(curr)
        {
            if(curr->val<x)
            {
                s->next=curr;
                s=s->next;
            }
            else
            {
                b->next=curr;
                b=b->next;
            }
            curr=curr->next;
        }
        b->next=nullptr;
        s->next=big->next;
        return small->next;
        
    }
};
