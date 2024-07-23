class Solution {
public:
    int maxVowels(string s, int k) {
        int maxcount=INT_MIN;
        int vc=0;
        int i=0,j=0;
        int n=s.size();
        while(j<n)
        {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            {
                vc++;

            }
            if(j-i+1==k)
            {
                maxcount=max(maxcount,vc);
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                    vc--;
                }
                i++;
            }




            j++;
        }
        return maxcount;
        
    }
};
