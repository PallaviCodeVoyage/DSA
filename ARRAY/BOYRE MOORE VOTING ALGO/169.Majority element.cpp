class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        
        // First pass: find the majority candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
         
         int occurrences = 0;
         for (int num : nums) {
             if (num == candidate) {
                 occurrences++;
             }
         }
         if (occurrences > nums.size() / 2) {
             return candidate;
        }
        
        return candidate;
    }
};////brute force 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int a:nums)
        {
            mp[a]++;
        }
        for(pair<int,int>m:mp)
        {
            if(m.second>(n/2))
            {
                return m.first;
            }
        }
        return 0;
        
    }
};
