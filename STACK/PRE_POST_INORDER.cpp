class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans; // Return an empty vector if root is nullptr

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr || !st.empty()) {
            // Reach the leftmost node
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            // Peek the node on top of the stack
            TreeNode* node = st.top();

            // Check if the right subtree has already been visited or doesn't exist
            if (node->right == nullptr || node->right == lastVisited) {
                ans.push_back(node->val); // Add to result as both left and right are processed
                st.pop();
                lastVisited = node;
            } else {
                curr = node->right; // Move to the right child
            }
        }

        return ans;
    }
};

/****/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode*current=root;
        while(current!=nullptr||!st.empty())
        {
            while(current!=nullptr)
            {
                ans.push_back(current->val);
                st.push(current);
                current=current->left;
                
            }
            current=st.top();
            st.pop();
           // ans.push_back(current->val);
            current=current->right;

        }
        return ans;
    }
};


/*****/
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
 */class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            // Traverse to the leftmost node
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            
            // Process the leftmost node and move to its right subtree
            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }

        return result;
    }
};
