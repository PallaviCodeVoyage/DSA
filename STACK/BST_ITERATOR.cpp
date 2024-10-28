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
class BSTIterator {
public:
vector<TreeNode*>v;
int n,point=0;

    BSTIterator(TreeNode* root) {
        TreeNode*curr=root;
        stack<TreeNode*>st;
        while(!st.empty()||curr)
        {
            while(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            v.push_back(curr);
            st.pop();
            curr=curr->right;

        }  
        n=v.size();


    }
    
    int next() {
        
            int ans= v[point]->val;
             point++;
        
       return ans;
        
    }
    
    bool hasNext() {
        if(point<=n-1)
        {
            return true;
        }
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


//***************************************************OPTIMISED APPROACH  O(H)&&O(1)*****************************************************/
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
class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper function to push all the left children of a given node
    // onto the stack. This prepares us to visit the smallest elements first.
    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);       // Push current node onto the stack
            node = node->left;    // Move to the left child
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        // Initialize the stack with the leftmost path from the root.
        // This sets up the stack to provide the smallest element first.
        pushLeft(root);
    }
    
    // Return the next smallest number
    int next() {
        // The top of the stack is the next smallest element
        TreeNode* node = st.top();
        st.pop();  // Remove it from the stack as we're visiting it

        // If the node has a right child, we need to process its leftmost path.
        if (node->right) {
            pushLeft(node->right);
        }

        // Return the value of the node we just visited
        return node->val;
    }
    
    // Return true if there are more nodes to visit, false otherwise
    bool hasNext() {
        // If the stack is not empty, there are still nodes to visit.
        return !st.empty();
    }
};
