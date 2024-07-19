class Solution {
public:
    int maxArea(vector<int>& height)
 {
        int l=0;
        int n=height.size();
        int r=n-1;
        int len=0;
        int h;
        int maxwater=INT_MIN;
        while(l<r)
        {
            len=(r-l);
           h=min(height[l],height[r]);
           maxwater=max(maxwater,h*len);
           (h==height[l])?l++:r--;

        }
        return maxwater;
        
    }
};
