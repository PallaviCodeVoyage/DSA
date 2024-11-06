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
vector<TreeNode*>solve(int start,int end)
{
    vector<TreeNode*>trees;
    if(start>end)
    {
        trees.push_back(nullptr);
        return trees;
        
    }

    for(int i=start;i<=end;i++)
    //ye loop stating that for the goven range 1 to n i am focused on making each node as the root
    {
        vector<TreeNode*>left=solve(start,i-1);
                vector<TreeNode*>right=solve(i+1,end);
                for(TreeNode*l:left)
                {
                    for(TreeNode*r:right)
                    {
                        TreeNode* node=new TreeNode();
                        node->val=i;
                        node->left=l;
                        node->right=r;
                        trees.push_back(node);
                    }
                }

    }
    return trees;
}
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
        {
            return {};
        }
        return solve(1,n);

        
    }
};
