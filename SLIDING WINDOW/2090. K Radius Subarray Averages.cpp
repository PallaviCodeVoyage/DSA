class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result(n,-1);
        if(n==0)
        {
            return nums;

        }
        if(n<2*k+1)
        {
            return result;
        }
        int i=k;
        int left=0;
        int start=left;
        int right=2*k;
        long long sum=0;
        while(left<=right)
        {
            sum=sum+nums[left];
            left++;
        }
                int no_of_elements=(2*k)+1;//size of  window
                result[i]=sum/no_of_elements;
                i++;
                right++;

                while(right<n)
                { int removed=nums[start];
                start++;
                 int added=nums[right];
                 sum=sum-removed+added;
                 result[i]=sum/no_of_elements;
                 right++;

                    i++;
                }
                return result;
        
    }
};


/*this question taught me to solve the sliding window pattern here we learnt a way inwhich we can avoide repeated task like calculating sum all over again*/
