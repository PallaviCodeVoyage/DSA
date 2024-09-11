memoised but passes 85/87 test cases
class Solution {
public:
    // Function to find the maximum number of envelopes
    int find(vector<vector<int>>& env, int idx, int prev, vector<vector<int>>& dp) {
        // Base case: If we've processed all envelopes
        if (idx == env.size()) {
            return 0;
        }

        // Check if the result is already computed
        if (dp[idx][prev + 1] != -1) {
            return dp[idx][prev + 1];
        }

        int taken = 0, not_taken = 0;

        // Check if we can take the current envelope
        if (prev == -1 || (env[idx][0] > env[prev][0] && env[idx][1] > env[prev][1])) {
            taken = 1 + find(env, idx + 1, idx, dp);
        }

        // Option not to take the current envelope
        not_taken = find(env, idx + 1, prev, dp);

        // Store the result in dp and return
        dp[idx][prev + 1] = max(taken, not_taken);
        return dp[idx][prev + 1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes by width and then by height in descending order
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        // Initialize DP array
        vector<vector<int>> dp(envelopes.size(), vector<int>(envelopes.size() + 1, -1));
        // Start the search
        return find(envelopes, 0, -1, dp);
    }
};


OPTIMISED

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort envelopes by width, and by height in descending order if widths are the same
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        // Step 2: Extract the heights
        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        // Step 3: Find the LIS in heights
        vector<int> dp; // dp will store the smallest ending value of LIS of each length

        for (int height : heights) {
            auto it = lower_bound(dp.begin(), dp.end(), height);
            if (it == dp.end()) {
                dp.push_back(height);
            } else {
                *it = height;
            }
        }

        return dp.size();
    }
};
