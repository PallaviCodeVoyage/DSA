/*****THIS IS LIS VARIANT*****/
O(N^2)
class Solution {
public:
    int dp[1001][1001]; // DP table for memoization

    int solve(const std::vector<std::vector<int>>& pairs, int idx, int prev) {
        if (idx >= pairs.size()) {
            return 0;
        }
        
        if (dp[idx][prev + 1] != -1) {//this prev+1 is so that the out of bound situation may not ocuur
            return dp[idx][prev + 1];
        }

        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[idx][0]) {
            take = 1 + solve(pairs, idx + 1, idx);
        }
        int skip = solve(pairs, idx + 1, prev);
        
        dp[idx][prev + 1] = std::max(take, skip);
        return dp[idx][prev + 1];
    }

    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        // Sort pairs by their end values
        std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Initialize the DP table with -1
        std::memset(dp, -1, sizeof(dp));
        
        return solve(pairs, 0, -1);
    }
};


/****GREEDY APPROACH****/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by the second element
        });

        int curr = INT_MIN;
        int count = 0;

        for (const auto& pair : pairs) {
            if (pair[0] > curr) {
                curr = pair[1];
                count++;
            }
        }

        return count;
    }
};
/*o(nlogn)*/
