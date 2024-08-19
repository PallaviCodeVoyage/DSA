class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* finding(vector<int>& inorder, vector<int>& postorder, int &postidx, int start, int endd) {
        if (start > endd) {
            return nullptr;
        }

        // The current root is the element at postidx in postorder array
        TreeNode* root = new TreeNode(postorder[postidx]);
        
        // Find the index of this root in the inorder array
        int i = mp[postorder[postidx]];
        postidx--;

        // Note: First build the right subtree and then the left subtree
        root->right = finding(inorder, postorder, postidx, i + 1, endd);
        root->left = finding(inorder, postorder, postidx, start, i - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int postidx = postorder.size() - 1; // Start from the last index
        return finding(inorder, postorder, postidx, 0, inorder.size() - 1);
    }
};
