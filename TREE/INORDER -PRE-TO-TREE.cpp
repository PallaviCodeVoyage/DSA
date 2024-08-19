//optimised using map whic provide lookup in O(1) and thus the dolution is having time comp of O(N) and space O(N) in brute force it becomes O(N^2) for time comp because we perform linear search to fing root in inorder
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
unordered_map<int,int>mp;

  TreeNode*finding(vector<int>preorder,vector<int>inorder,int startidxinorder,int endidx,int &preorderidx)
  {
    if(startidxinorder>endidx)
    {
        return nullptr;
    }

    TreeNode*root=new TreeNode(preorder[preorderidx]);
   

    int i=mp[preorder[preorderidx]];
     preorderidx++;
    root->left=finding(preorder,inorder,startidxinorder,i-1,preorderidx);
    root->right=finding(preorder,inorder,i+1,endidx,preorderidx);
    return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++)
        {
          mp[inorder[i]]=i;
        }
        int preorder_index = 0;

        TreeNode*root=finding(preorder,inorder,0,inorder.size()-1,preorder_index);
        return root;
        
    }
};
