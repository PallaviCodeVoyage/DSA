class Solution {
public:
    int solve(vector<int>& nums, int n, int i, vector<int>& memo) {
        // Base case: If we've reached the end of the array, return 0
        if (i >= n) {
            return 0;
        }
        
        // If the subproblem is already solved, return the stored result ,this is the basic template used in rec+memoisation methods
        if (memo[i] != -1) {
            return memo[i];
        }
        
        // Recursively solve the problem by including or excluding the current house because  we have only two choices either we can rob or leave the house ie take or skip
        int select = nums[i] + solve(nums, n, i + 2, memo); // Include current house
        int skip = solve(nums, n, i + 1, memo); // Skip current house
        
        // Store the result in the memo array and return it
        memo[i] = max(select, skip);
        return memo[i];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1); // Initialize memo array with -1
        return solve(nums, n, 0, memo);//this shows that we are beginning from the house numbered as 0 .
    }
};
