/*brute force with time complexity O(N(sqrt(N))*/
/*the very first point is that the length os the substring should be such as if it must completely divide the length of the given string*/
/*the no of times the substring is repeated is basically the quotient of (n/l) where l is the len of substring and n is of string*/
/*and the third logic is that if we repeat the substring then it is unnecessary to repeat the substring of length greater than the half of the length of given substring*/
/******code*****/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int len=s.length();
      for(int l=len/2;l>=1;l--)
        {
          if(len%l==0)//point 1
          {
            string str=s.substr(0,l);
            string ans="";
            int times=len/l;//point 2
            while(times--)
              {
                ans+=str;
                
              }
            if(ans==s)
            {
              return true;
            }
          }
        }
      return false;
    }
};


/*approach 2 using kmp time complexity is O(N)*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        // Build the LPS array using the KMP preprocessing step
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Check the last value of LPS array for potential repeated substring length
        int len_lps = lps[n - 1];
        
        // Calculate the length of the potential repeated substring
        int len_substring = n - len_lps;
        
        // Check if the substring length divides the total length evenly
        if (len_lps > 0 && n % len_substring == 0) {
            return true;
        } else {
            return false;
        }
    }
};
