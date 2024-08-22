
1. Recursive Approach

Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree due to recursion stack.
cpp

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
2. Iterative Approach using Queue

Space Complexity: O(n) for the queue
cpp
Copy code
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        while (!queue.empty()) {
            TreeNode* n1 = queue.front(); queue.pop();
            TreeNode* n2 = queue.front(); queue.pop();
            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;
            queue.push(n1->left);
            queue.push(n2->left);
            queue.push(n1->right);
            queue.push(n2->right);
        }
        return true;
    }
};
3. Iterative Approach using Stack
Time:O(N)
Space Complexity: O(n) for the stack

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> stack;
        stack.push(p);
        stack.push(q);
        while (!stack.empty()) {
            TreeNode* n1 = stack.top(); stack.pop();
            TreeNode* n2 = stack.top(); stack.pop();
            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;
            stack.push(n1->left);
            stack.push(n2->left);
            stack.push(n1->right);
          stack.push(n2->right);
          }
        return true;
    }
};
            stack.push(n2->right);
        }
        return true;
    }
};
