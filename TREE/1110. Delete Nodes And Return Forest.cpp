#include <vector>
#include <unordered_set>
using namespace std;
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};*/

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        root = helper(root, toDeleteSet, forest);
        if (root) {
            forest.push_back(root);
        }
        return forest;
    }
    
private:
    TreeNode* helper(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        
        // Recursively traverse the left and right children
        node->left = helper(node->left, toDeleteSet, forest);
        node->right = helper(node->right, toDeleteSet, forest);
        
        // If the current node needs to be deleted
        if (toDeleteSet.count(node->val)) {
            if (node->left) {
                forest.push_back(node->left);
            }
            if (node->right) {
                forest.push_back(node->right);
            }
            // Delete the current node by returning nullptr
            return nullptr;
        }
        
        // Return the node if it's not deleted
        return node;
    }
};
