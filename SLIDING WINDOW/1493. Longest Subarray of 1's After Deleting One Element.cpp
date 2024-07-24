class Solution {
public:
    /*int find(vector<int> nums, int foi) {
        int curr = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == foi) {
                continue;
            }
            if (nums[i] != 0) {
                curr++;
                ans = max(ans, curr);
            } else {
                curr = 0;
            }
        }
        return ans;
    }

    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
                ans = max(ans, find(nums, i));
            }
        }
        if (count == 0) {
            return n - 1;
        }
        return ans;
    }*/

    int longestSubarray(vector<int>& nums) {
 int n = nums.size();
        int ans = 0;
        int z = 0;   // count of zeros in the current window
        int i = 0;   // left pointer of the window

        for (int j = 0; j < n; j++) {  // right pointer of the window
            if (nums[j] == 0) {
                z++;
            }

            // If there are more than 1 zero in the window, move the left pointer `i`
            while (z > 1) {
                if (nums[i] == 0) {
                    z--;
                }
                i++;
            }

            // Update the maximum length of the window, subtracting 1 to account for one possible deletion
            ans = max(ans, j - i);
        }

        return ans;
    }
};
