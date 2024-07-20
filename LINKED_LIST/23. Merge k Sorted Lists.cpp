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
struct comp{
 bool operator()(ListNode*a,ListNode*b)
 {
    return a->val>b->val;
 }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        for(ListNode*a:lists)
        {
            if(a!=nullptr)
            {
                pq.push(a);
            }
        }

        ListNode dummy(0,nullptr);
        ListNode*temp=&dummy;
        while(!pq.empty())
        {
            temp->next=pq.top();
            pq.pop();
            temp=temp->next;
            if(temp->next!=nullptr)
            {
                pq.push(temp->next);
            }

        }

        return dummy.next;

        
        
    }
};
