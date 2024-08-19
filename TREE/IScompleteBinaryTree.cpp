#include <queue>
#include <iostream>
using namespace std;
/*
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool encounteredNull = false;

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current == nullptr) {
                encounteredNull = true; // If we encounter a null node, set the flag
            } else {
                if (encounteredNull) {
                    // If we encounter a non-null node after a null node, it's not complete
                    return false;
                }
                q.push(current->left);
                q.push(current->right);
            }
        }

        return true; // If we processed the entire tree without issues, it's complete
    }
};
//main idea is ki if u encounter null then after that u must not get any node and this is valid in any level
