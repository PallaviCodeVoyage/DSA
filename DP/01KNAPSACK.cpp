//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int dp[1001][1001];
    // Function to return max value that can be put in knapsack of capacity W.
       int solve(int capacity, vector<int>& wt, vector<int>& val, int idx) {
        // Base cases: No more items or capacity is 0
        if (idx >= wt.size() || capacity == 0) {
            return 0;
        }

        // Check if the result is already computed
        if (dp[idx][capacity] != -1) {
            return dp[idx][capacity];
        }

        // If the current item can't fit in the knapsack, skip it
        if (wt[idx] > capacity) {
            return dp[idx][capacity] = solve(capacity, wt, val, idx + 1);
        }
        
        // Either include the current item or exclude it
        int include = val[idx] + solve(capacity - wt[idx], wt, val, idx + 1);
        int exclude = solve(capacity, wt, val, idx + 1);

        // Store the result in dp table and return
        return dp[idx][capacity] = max(include, exclude);

    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        memset(dp,-1,sizeof(dp));
        return solve(W,wt,val,0);
        // Your code here
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
