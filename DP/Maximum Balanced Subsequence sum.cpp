//RECURSIVE APPROACH
class Solution {
public:

long long solve(vector<int>num,int prev,int indx)
{
    if(indx==num.size())
    {
        return 0;
    }
    long long taken=0,not_taken=0;
    if(prev==-1||num[indx]-indx>=num[prev]-prev)
    {
        taken=num[indx]+solve(num,indx,indx+1);
    }
    not_taken=solve(num,prev,indx+1);
    return max<long long>(taken,not_taken);
}
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int el=*max_element(nums.begin(),nums.end());
        if(el<0)
        {
            return el;//agar hmare pas aur v negative numbers hain and along with that if we add negative to a negative num then vo aur chota ho jaeg 
        }

       return solve(nums,-1,0);
        
    }
};

OPTIMISED
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};
