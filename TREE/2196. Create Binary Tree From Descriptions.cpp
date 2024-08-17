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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>ischild;

        for(vector<int>v:descriptions)
        {
            int parent=v[0];
            int child=v[1];
            int lc=v[2];

            if(mp.find(parent)==mp.end())
            {
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end())
            {
                mp[child]=new TreeNode(child);
            }
            if(lc==0)
            {
                mp[parent]->right=mp[child];
            }
            else
            {
                 mp[parent]->left=mp[child];
            }
            ischild.insert(child);

           
        }

        for(vector<int>v:descriptions)
        {
            if(ischild.find(v[0])==ischild.end())
            {
                return mp[v[0]];
            }
        }
        return nullptr;
        
    }
};
