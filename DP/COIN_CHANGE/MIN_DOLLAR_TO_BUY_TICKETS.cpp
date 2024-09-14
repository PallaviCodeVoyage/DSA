class Solution {
public:
    int dp[366];  // dp array to store the minimum cost for each day index
    
    int solve(vector<int>& days, vector<int>& cost, int idx) {
        // Base case: if all days have been processed, no more cost is needed
        if (idx >= days.size()) {
            return 0;
        }
        
        // Check if the result for this day index has already been computed
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        // Option 1: Buy a 1-day pass
        int if_one_day_pass = cost[0] + solve(days, cost, idx + 1);
        
        // Option 2: Buy a 7-day pass
        int if_7_day_pass;
        int j = idx;
        // Find the day that is beyond the 7-day limit from the current day
        while (j < days.size() && days[j] < days[idx] + 7) {
            j++;
        }
        if_7_day_pass = cost[1] + solve(days, cost, j);
        
        // Option 3: Buy a 30-day pass
        int if_30_day_pass;
        j = idx;
        // Find the day that is beyond the 30-day limit from the current day
        while (j < days.size() && days[j] < days[idx] + 30) {
            j++;
        }
        if_30_day_pass = cost[2] + solve(days, cost, j);
        
        // Store the minimum cost in the dp array and return it
        dp[idx] = min(if_one_day_pass, min(if_7_day_pass, if_30_day_pass));
        return dp[idx];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Initialize dp array with -1 (indicating uncomputed states)
        memset(dp, -1, sizeof(dp));
        return solve(days, costs, 0);
    }
};
