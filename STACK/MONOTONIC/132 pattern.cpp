
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;

        stack<int> monoStack;
        int s3 = INT_MIN; // Initialize s3 as the minimum integer value

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < s3) // If we find a number smaller than s3, then a 132 pattern is found
                return true;

            // Keep updating s3 to be the maximum value popped from the stack that is less than the current number
            while (!monoStack.empty() && nums[i] > monoStack.top()) {
                s3 = monoStack.top();
                monoStack.pop();
            }

            monoStack.push(nums[i]); // Push the current number onto the stack
        }

        return false;
    }
};
