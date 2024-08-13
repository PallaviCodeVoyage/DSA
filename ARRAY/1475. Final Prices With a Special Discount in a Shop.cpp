class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(prices.size(),0);
        ans[n-1]=prices[n-1];
        int j;
        for(int i=0;i<n-1;i++)
        {
            for( j=1+i;j<n;j++)
            {
                if(prices[i]>=prices[j])
                {
                    ans[i]=prices[i]-prices[j];
                    break;
                }

            }
            if(j==n)
            {
                ans[i]=prices[i];
            }
        }
        return ans;

        
    }
};


//second O(N)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> s;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }
            ans[i] = prices[i] - (s.empty() ? 0 : s.top());
            s.push(prices[i]);
        }
        
        return ans;
    }
};
