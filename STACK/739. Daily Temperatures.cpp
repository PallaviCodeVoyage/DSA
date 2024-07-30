class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();     // Get the size of the temperatures array
        vector<int> ans(n, 0);           // Initialize the answer array with all 0s
        stack<int> st;                   // Initialize an empty stack

        for (int i = 0; i < n; ++i) {    // Loop through each temperature
            // While stack is not empty and the current temperature is greater than 
            // the temperature at the index stored at the top of the stack
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();      // Get the index from the top of the stack
                st.pop();                // Pop the index from the stack
                ans[idx] = i - idx;      // Calculate the number of days and store it in the answer array
            }
            st.push(i);                  // Push the current index onto the stack
        }
        
        return ans;                      // Return the final answer array
    }
};
