// class Solution {
// public:
// vector<int>ans;
// vector<int>temp;
// void solve(int idx,int prev,vector<int>&nums)
// {
//     if(idx>=nums.size())
//     {
//         if(ans.size()<temp.size())
//         {
//             ans=temp;
//         }
//          return;
//     }

//     if(prev==-1||nums[idx]%nums[prev]==0)
//     {
//         temp.push_back(nums[idx]);
//         solve(idx+1,idx,nums);
//         temp.pop_back();
//     }
//     solve(idx+1,prev,nums);
  
// }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int prev=-1;
//         solve(0,prev,nums);
//         return ans;

        
//     }
// };
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);        // length of subset ending at i
        vector<int> prev(n, -1);     // previous index in the subset
        int maxLen = 1, lastIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the subset
        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
