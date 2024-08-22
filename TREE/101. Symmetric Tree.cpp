1. Recursive Approach
Description: This method recursively checks if the left subtree is a mirror reflection of the right subtree. This is a direct and intuitive approach.
Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the tree (due to recursion stack).

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};

2. Iterative Approach using Queue
Description: Instead of recursion, this approach uses a queue to iteratively compare the nodes in the left and right subtrees. Pairs of nodes (mirroring each other) are enqueued and dequeued to check their symmetry.
Time Complexity: O(n)
Space Complexity: O(n) for the queue

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();

            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};
