class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minin=-1,maxin=-1,ci=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<minK||nums[i]>maxK)
            {
                ci=i;
            }
            if(nums[i]==minK)
            {
                minin=i;
            }
            if(nums[i]== maxK)
            {
                maxin=i;
            }
            long long smaller=min(minin,maxin);
            long long temp=(smaller-ci);
               ans+=(temp<=0)?0:temp;
        }
        return ans;
        
    }
};
