//same as combination finding in coin change but the condition 1,2 is same as 2,1
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Use long long for dp to avoid overflow issues
        vector<long long> dp(target + 1, 0);
        // Base case: there's exactly 1 way to make target 0 (by not picking any numbers)
        dp[0] = 1;
        
        // Iterate through all possible target amounts from 1 to the given target
        for (int i = 1; i <= target; i++) {
            // For each number in the nums array, see if it can contribute to the current target i
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];  // Add the number of ways to make (i - num) to dp[i]
                }
            }
        }

        // dp[target] will contain the number of ways to form the target
        return dp[target];
    }
};

///this approach passes all test cases
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[1001][201];
    int solve(vector<int>& nums, int target, int idx) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        int take_idx    = solve(nums, target - nums[idx], 0);
        int reject_idx  = solve(nums, target, idx+1);
        
        return t[target][idx] = take_idx + reject_idx;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        
        return solve(nums, target, 0);
    }
};
