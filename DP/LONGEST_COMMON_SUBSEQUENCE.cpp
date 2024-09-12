
//what does a particular element of m dp or meo array state that what is the length of lcs of string 1 of length i and string 2 of length j
class Solution {
public:
  int solve(string &a,string &b,int i,int j,vector<vector<int>>& v)
  {
    if(i>=a.size()||j>=b.size())
    {
        return 0;
    }
    if(v[i][j]!=-1)
    {
        return v[i][j];
    }
     if(a[i]==b[j])
    {
        v[i][j]=1+solve(a,b,i+1,j+1,v);

    }
    else
    {
        v[i][j]=max(solve(a,b,i+1,j,v),solve(a,b,i,j+1,v));//hero step ki main iss element ko nhi lerri bcoz not same in both strings at a given index but now the dilemma is i have option either to look fo a match to this
      //element in string 2 or increament string 1 index to seek for a match of string 2 element
    }

    return v[i][j];
  }
    int longestCommonSubsequence(string text1, string text2) {
        int s1=text1.length();
        int s2=text2.length();
        vector<vector<int>>v(s1,vector<int>(s2,-1));
        return solve(text1,text2,0,0,v);
        
    }
};
