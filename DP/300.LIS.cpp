class Solution {
public:

  int dp[2501][2501];
   

  int solve(vector<int>& nums,int pidx,int cidx)
  { 

     int acc=0;
      int skip=0;
    if(cidx>=nums.size())
    {
     return 0;
    }
    if(pidx!=-1 && dp[cidx][pidx]!=-1)
    {
        return dp[cidx][pidx];
    }
     
     if(pidx==-1||nums[pidx]<nums[cidx])
     {
         acc=1+solve(nums,cidx,cidx+1);

     }
     skip =solve(nums,pidx,cidx+1);
     if(pidx!=-1)
     {
        
     return dp[cidx][pidx]=max(skip,acc);
     }
     else
     {
        return max(skip,acc);
     }

  }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,-1,0);
        return ans;

        
    }
};




//Approach-2 (Bottom Up DP) O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxL = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
    }
};
