class Solution {
public:
vector<int>fill(string s)
{
    int n=s.length();
    int m=0;
    vector<int>ans(n);
    int i=1;
    ans[0]=0;
    while(i<n)
    {
        if(s[i]==s[m])
        {
            m++;
            ans[i]=m;
            i++;
        }
        else
        {
            if(m!=0)
            {
                m=ans[m-1];
            }
            else
            {
                ans[i]=0;
              i++;
            }
        }
    }
    return ans;
}
    string longestPrefix(string s) {
        vector<int>lps=fill(s);
        int l=lps.back();
        string ans=s.substr(0,l);
        return ans;
        
    }
};
