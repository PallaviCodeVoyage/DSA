brute Force
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
 int ans=0;

 int calans(TreeNode*ancestor,TreeNode*desc)
 {
    if(ancestor==nullptr||desc==nullptr)
    {
        return 0;
    }

    ans=max(ans,abs(ancestor->val-desc->val));
    int l=calans(ancestor,desc->left);
    int r=calans(ancestor,desc->right);
     
     return max(ans,max(l,r));

 }
 void func(TreeNode*root)
 {
    if(root==nullptr)return;
    calans(root,root->left);
    calans(root,root->right);

    func(root->left);
    func(root->right);
 }
 
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr)return 0;
        func(root);
        return ans;
    }
};


Optimised

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
  int cal(TreeNode*root,int lval,int sval)
  {
    if(root==nullptr)//null wali condition
       {
        return lval-sval;
       }

     lval=max(root->val,lval);
     sval=min(root->val,sval);


    int leftans=cal(root->left,lval,sval);
    int rightans=cal(root->right,lval,sval);

    return(max(leftans,rightans));  
  }
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr)return 0;
        int ans=cal(root,root->val,root->val);
        return ans;
        
    }
};
