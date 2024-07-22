#include <vector>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int i = 0;
        int j = 0;
        long int sum = 0;
        int min_s =nums.size()+1; // Initialize with a value greater than the size of nums
        int s = nums.size();
        while (j < s) {
            sum += nums[j];
          //shrinking
            while (sum >= target) {
                min_s = std::min(min_s, (j - i + 1));
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (min_s == s + 1) ? 0 : min_s; // If min_s is unchanged, return 0
    }
};
