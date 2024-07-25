/*class Solution {
public:

int find(vector<int>nums,int i,int j)
{
  /*  int ans=INT_MIN;
    while(i<=j)
    {
        if(nums[i]>ans)
        {
            ans=nums[i];
        }
        i++;

    }
    return ans;
}
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        int a=INT_MIN;
        int i=0;
        for(;i<k;i++)
        {
          if(nums[i]>a)
          {
            a=nums[i];
          }
        }
        ans.push_back(a);
        int j=i;
        i=1;
        while(j<n)
        {
            a=find(nums,i,j);
            ans.push_back(a);
            i++;
            j++;
          
        }
        return ans;
      vector<int>ans;
      deque<int>d;
      for(int i=0;i<nums.size();i++)
      {
        while(!d.empty()&& d.front()<=i-k)
        {
            d.pop_front();
        }
        while(!d.empty()&&nums[i]>nums[d.back()])
        {
            d.pop_front(); 
        }
        d.push_back(i);
        if(i>=k-1)
        {
            ans.push_back(nums[d.front()]);
        
        }
      }
       return ans;

    }
};
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> d;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            while (!d.empty() && d.front() <= i - k) 
            {
                d.pop_front();
            }
            
            // Remove elements from the back of the deque if they are smaller
            // than the current element because they are not useful
            while (!d.empty() && nums[i] > nums[d.back()])
            {
                d.pop_back();  // Corrected from pop_front to pop_back
            }
            
            // Add the current element index to the deque
            d.push_back(i);
            
            // The front of the deque is the largest element in the current window
            if (i >= k - 1) {
                ans.push_back(nums[d.front()]);
            }
        }

        return ans;
    }
};
