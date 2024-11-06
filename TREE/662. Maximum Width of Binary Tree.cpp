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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        if(root==nullptr)
        {
            return 0;
        }
       unsigned long long ans=0;

        q.push({root,0});
        while(!q.empty())
        {
            int s=q.size();
           
           unsigned long long l=q.front().second;
           unsigned long long r=q.back().second;
            ans=max(ans,r-l+1);
            while(s>0)
            {
                TreeNode*node=q.front().first;
               unsigned long long parent_indx=q.front().second;
                q.pop();
                if(node->left!=nullptr)
                {
                    q.push({node->left,(2*parent_indx)+1});
                }
                if(node->right!=nullptr)
                {
                    q.push({node->right,(2*parent_indx)+2});
                }

                s--;
            }
         

        }
        return ans;
    }
};
