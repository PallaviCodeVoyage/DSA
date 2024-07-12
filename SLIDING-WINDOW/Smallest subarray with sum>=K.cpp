//okay so in this we need to find out the length of smallest subarray with sum >= k,this hints towards the usage of sliding window as the subarray is need to be found
#include <vector>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int i = 0;
        int j = 0;
        long int sum = 0;
        int min_s =nums.size()+1; // Initialize with a value greater than the size of nums,this simply means that right now the subarray is of length greater 
      //than the legth of given array and later if any subarray would be present it would be either equal or smaller to the length of given array
        int s = nums.size();
        while (j < s) {
            sum += nums[j];
          /* and here in the loop below once we find the ans greater than or equal to k we start increamenting i (left pointer) and check repeatedly if the sum is still greater 
          and if yess we again increament i in order to shrin the size as much as possible*/
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

