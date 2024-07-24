class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        if(k==n)
        {
            int i=0,sum=0;
            while(i<n)
            {
                sum=sum+cardPoints[i];
                i++;

            }
            return sum;
        }
        int sum=0;
        int ans=0;

        for(int i=0;i<k;i++)
        {
            sum=sum+cardPoints[i];

        }
        ans=sum;
          for (int i = 0; i < k; ++i) {
            // Slide the window: remove one from the start and add one from the end
            sum = sum - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            // Update maxScore with the maximum sum found
            ans = max(ans, sum);
        }
          return ans;
        
    }
};
