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
int ans=INT_MIN;
 void solve(TreeNode*a,TreeNode*b)
 {
    if(!a||!b)
   {
    return;
   }
    ans=max(ans,abs(a->val-b->val));
    solve(a,b->left);
    solve(a,b->right);

 }
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr)return 0;
        solve(root,root->left);
        solve(root,root->right);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return ans;
        
    }
};



*****************************************
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) return maxVal - minVal;

        // Update min/max along the path
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        // Go to left and right child
        int left = dfs(node->left, minVal, maxVal);
        int right = dfs(node->right, minVal, maxVal);

        return max(left, right);
    }
};
