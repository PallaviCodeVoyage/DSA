#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        dfs(root, 0, rightView);
        return rightView;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& rightView) {
        if (!node) return;

        // If this is the first time we're visiting this depth, add the node's value
        if (depth == rightView.size()) {
            rightView.push_back(node->val);
        }

        // First explore the right subtree, then the left subtree
        dfs(node->right, depth + 1, rightView);
        dfs(node->left, depth + 1, rightView);
    }
};/*now here we learnt that whenever we encounter the depth to be equal to the size of array we means that a very first node at particular level or depth is encountered

//reverse BFS
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==nullptr)
        {
            return ans;

        }
        q.push(root);
        while(!q.empty())
        {
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++)
            {
                TreeNode*cur=q.front();
                q.pop();
                if(i==0)
                {
                    ans.push_back(cur->val);
                }

                   if (cur->right) q.push(cur->right);
                if (cur->left) q.push(cur->left);
            }

        }
        return ans;
    }
};
