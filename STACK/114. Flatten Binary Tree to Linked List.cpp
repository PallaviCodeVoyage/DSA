class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            // Push the right and left children onto the stack (if they exist)
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);

            // Update the current node's pointers
            if (!st.empty()) curr->right = st.top(); // Next node in preorder
            curr->left = nullptr; // Set left child to nullptr
        }
    }
};
/****APPROACH 2***/
/***O(N)&O(N)
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Vector to store nodes in preorder traversal
        vector<TreeNode*> vec;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        // Preorder traversal to fill vec
        while (curr != nullptr || !st.empty()) {
            while (curr) {
                vec.push_back(curr);
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            curr = curr->right;
        }

        // Rearranging nodes to form the flattened list
        int n = vec.size();
        for (int i = 0; i < n - 1; ++i) {
            vec[i]->left = nullptr;     // Set left child to nullptr
            vec[i]->right = vec[i + 1]; // Set right child to the next node in preorder
        }
        
        // Set the last node's left and right pointers to nullptr
        vec[n - 1]->left = nullptr;
        vec[n - 1]->right = nullptr;
    }
};
