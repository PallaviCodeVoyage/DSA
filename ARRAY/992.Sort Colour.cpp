/* two pointersXXXXX3 pointers ie DUTCH NATIONAL FLAG ALGO*/
/*HINT: THE ELEMENTS NEEDS TO BE SORTED IN ASC ORDER BUT ARE ONLY  3 MEMBERS 0,1,2*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int m=0;
        while(m<=j)
        {
          if(nums[m]==2)
          {
            swap(nums[m],nums[j]);
            
            j--;

          }
          else if(nums[m]==1)
          {
            m++;
          }
          else if(nums[m]==0)
          {
            swap(nums[m],nums[i]);
            i++;
            m++;
          }

        }
    }
};
