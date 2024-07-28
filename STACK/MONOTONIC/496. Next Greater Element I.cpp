/***INCREASING STACK****/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(nums2.size(), -1); // Stores next greater element for each element in nums2
        stack<int> s;
        unordered_map<int, int> indexMap; // Map to store indices of elements in nums2
        
        // Populate index map
        for (int i = 0; i < nums2.size(); ++i)
            indexMap[nums2[i]] = i;
        
        // Traverse nums2 to find next greater elements
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreater[indexMap[s.top()]] = num;
                s.pop();
            }
            s.push(num);
        }
        
        // Result vector
        vector<int> result;
        
        // Fill result vector with next greater elements for nums1
        for (int num : nums1)
            result.push_back(nextGreater[indexMap[num]]);
        
        return result;
    }
};
