class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        
        // Calculate sum of first k elements
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        
        double maxSum = sum;
        
        // Iterate through the array starting from index k
        for (int i = k; i < n; ++i) {
            // Update sum by subtracting the element going out of the window and adding the new element coming into the window
            sum = sum - nums[i - k] + nums[i];
            // Update maxSum if necessary
            maxSum = max(maxSum, sum);
        }
        
        // Return the maximum average
        return maxSum / k;
    }
};
