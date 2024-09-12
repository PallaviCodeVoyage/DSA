
/*class Solution {
public:

int maxPoints(vector<int>& nums, int i) {
    if (i >= nums.size()) return 0;

    int currentVal = nums[i];
    int take = currentVal;

    // Collect all points if we take nums[i]
    vector<int> remainingNums;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != currentVal && nums[j] != currentVal - 1 && nums[j] != currentVal + 1) {
            remainingNums.push_back(nums[j]);
        }
        else if(j!=i&&nums[j]==currentVal)
        {
            remainingNums.push_back(nums[j]);
        }
    }
    
    // Take nums[i] and call recursively on the remaining elements
    take += maxPoints(remainingNums, 0);
    
    // Skip nums[i] and move to the next element
    int skip = maxPoints(nums, i + 1);

    return max(take, skip);
}

    int deleteAndEarn(vector<int>& nums) {
        return maxPoints(nums,0);
    }
};*/
/*THE LOWER PROBLEM IS SAME AS HOUSE ROBBER*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Step 1: Create a frequency map
        map<int, int> freq;
        int maxNum = 0;
        for (int num : nums) {
            freq[num] += num;
            maxNum = max(maxNum, num);
        }

        // Step 2: Use DP to find max points
        vector<int> dp(maxNum + 1, 0);
        dp[1] = freq[1];  // Base case for 1

        for (int i = 2; i <= maxNum; i++) {//agar main iss element ko include kru ya na kru to jo mujhe max ans derra hain main usse dp main rhungi along with it also agr main include krri hu to iss index tk msain usse ek chote lement k sum ko to include krr hi ni skti that is why dp[i-2]
            dp[i] = max(dp[i-1], dp[i-2] + freq[i]);
        }

        return dp[maxNum];
    }
};
