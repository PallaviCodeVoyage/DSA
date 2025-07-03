// class Solution {
// public:
//     vector<string> v;

//     void solve(TreeNode* node, string& s) {
//         if (!node) return;

//         string curr = to_string(node->val);
//         s += curr;

//         if (!node->left && !node->right) {
//             // Only push when it's a leaf
//             v.push_back(s);
//         } else {
//             solve(node->left, s);
//             solve(node->right, s);
//         }

//         s.erase(s.end() - curr.size(), s.end()); // backtrack full value
//     }

//     int sumNumbers(TreeNode* root) {
//         if (!root) return 0;
//         string s = "";
//         solve(root, s);

//         int ans = 0;
//         for (auto& path : v) {
//             ans += stoi(path);
//         }
//         return ans;
//     }
// };
*****************************************
class Solution {
public:
    int dfs(TreeNode* node, int currSum) {
        if (!node) return 0;

        currSum = currSum * 10 + node->val;

        if (!node->left && !node->right)
            return currSum;

        int a= dfs(node->left, currSum) ;int b= dfs(node->right, currSum);
        return a+b;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
