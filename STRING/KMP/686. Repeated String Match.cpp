/*class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        //this time b is going to be a pattern as i am looking for b in concatinated string made up of a;
        string c="";
        int count=0;
        while(c.length()<b.length())
        {
            c=c+a;
            count++;

        }
         extra concatenation in order to handel edge case where the string may not 
           completely fit or in simple terms the required string khi towards end main
           hain in the concatenated string
        if(c.find(b)!=string::npos)
        {
            return count;
        }
        else
        {
            c=c+a;
            count++;
            if(c.find(b)!=string::npos)
           {
            return count;
           }

        }
        return -1;

    }
};
*/






class Solution {
public:

   vector<int>fill(string a)
      {
          int n=a.length();
          vector<int>lps(n);
          int i=1;
          int max=0;
          lps[0]=0;
          while(i<n)
          {
            if(a[i]==a[max])
            {
                max++;
                lps[i]=max;
                i++;
            }
            else
            {
                if(max!=0)
                {
                    max=lps[max-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
          }
          return lps;
      }

//same rule of string that b is pat and a is main string
      bool kmp(string a,string b,vector<int>lps)
      {
        int i=0;//for text
        int j=0;//for pattern
        int t=a.length();
        int p=b.length();
        while(i<t)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            if(j==p)
            {
                return true;
            }
            else if(i<t&&a[i]!=b[j])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;

      }
   int repeatedStringMatch(string a, string b) 
{ if(a == b) return 1;
    vector<int>lps=fill(b);//this time b is the pattern for the reason that a is rep and b is looked in a

   int al=a.length();
   int bl=b.length();
   //int num=(bl/al)+1;
              int count = 1;
        string source = a;
        while(source.size() < b.size()){
            source+=a;
            count++;
        }
        
        if(kmp(source,b,lps)) 
            return count;
        
        if(kmp(source+a,b,lps)) 
            return count+1;
return -1;
}
};


//same as 459 butmch easy as str and pat were given but in that one we needed to figure out
