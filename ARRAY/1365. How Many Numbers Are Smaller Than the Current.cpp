class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        /*for(int i=0;i<nums.size();i++)
        
        { 
             int count=0;

            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<nums[i])
                {
                    count++;
                }

            }
            ans.push_back(count);


*/
  vector<pair<int,int>>mp;
  for(int i=0;i<nums.size();i++)
  {
    mp.push_back(make_pair(nums[i],i));
  }
  sort(mp.begin(),mp.end());
  int a=0;
  for(int i=0;i<nums.size();i++)
  {
    if(i==0||mp[i].first!=mp[i-1].first)
    {
      a=i;
    }
      ans[mp[i].second]=a;
  }
  return ans;
  
    }
};
