//{ Driver Code Starts
//O(N)
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:



    bool allzero(vector<int>v)
    {
        
     for(auto a:v)
     {
         if(a!=0)
         {
             return false;
         }
     }
     return true;
    }
	int search(string pat, string txt) {
	    // code here
	    int l1=txt.length();
	    vector<int>occ(26,0);
	    int ans=0;
	    
	    int l2=pat.length();
	    for(int i=0;i<l2;i++)
	    {
	         occ[pat[i]-'a']++;
	        
	    }
	    
	    int i=0,j=0;
	    while(j<l1)
	    {
	        occ[txt[j]-'a']--;
	        if(j-i+1==l2)
	        {
	            if(allzero(occ))
	            {
	                ans++;
	                
	                
	             }
	             
	             occ[txt[i]-'a']++;
	             i++;
	             
	             
	        }
	        j++;
	        
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
