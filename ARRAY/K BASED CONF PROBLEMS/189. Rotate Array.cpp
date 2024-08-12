/O(N)&O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n
        
        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};
//partially accepted
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>copy(n+1);
      while(k>0)
      {
          for(int i=0;i<n;i++)
        {
            
            copy[i+1]=nums[i];
        }
        
        for(int i=1;i<n;i++)
        {
            nums[i]=copy[i];
        }

        nums[0]=copy[n];
        k--;

        
      }
     
    }
};
