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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
ListNode*prev,*slow,*fast;
ListNode*find(ListNode*head)
{
   
    slow=head;
    fast=head;
    while(fast&&fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
    
    
    
    }
    TreeNode* sortedListToBST(ListNode* head) {
         if(head==nullptr)
             {
                return nullptr;
             }
            if(head->next==nullptr)
             {
                TreeNode*node=new TreeNode(head->val);
                return node;
             }
             
        ListNode*mid=find(head);
        //detaching list 1 smaller elements containing than the root node at the middle
        prev->next=nullptr;
        //mid is ointing to beginning of the rest half node;
        //creating tree;
        TreeNode*root=new TreeNode(mid->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);

        return root;

    }
};
