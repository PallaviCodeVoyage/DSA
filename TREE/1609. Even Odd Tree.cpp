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
    bool isEvenOddTree(TreeNode* root) {
        if(root==nullptr)
        {
            return false;
        }
        bool asc=true;
        bool desc=true;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {int prev_odd=INT_MAX;
                int prev_even=INT_MIN;
            int s=q.size();
            while(s>0)
            {
                TreeNode*node=q.front();
                q.pop();
                
                if(level%2==0)
                {
                    if(node->val%2!=0)
                    {
                         if(prev_even<node->val)
                        {
                          if(node->left)
                        {
                            q.push(node->left);
                        }
                        if(node->right)
                        {
                            q.push(node->right);
                        }


                        }
                        else
                        {
                            return false;
                        }

                        prev_even=node->val;
                    }
                    else
                    {
                        return false;
                    }

                }
                else
                {
                    
                    if(node->val%2==0)
                    {
                        if(prev_odd>node->val)
                        {
                          if(node->left)
                        {
                            q.push(node->left);
                        }
                        if(node->right)
                        {
                            q.push(node->right);
                        }


                        }
                        else
                        {
                            return false;
                        }

                        prev_odd=node->val;
                    }
                    else
                    {
                        return false;
                    }

                }
                s--;


            }
            level++;
        }
        return true;
        
    }
};
