//T.C : O(n*n*n)
class Solution {
public:
    int n;
    int t[1001][1001];
    
    bool predecessor(string& prev, string& curr) {
        int M = prev.length();
        int N = curr.length();
        
        if(M >= N || N-M != 1)
            return false;
        
        int i = 0, j = 0;
        while(i < M && j < N) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==M;
    }
    
    int lis(vector<string>& words, int prev_idx, int curr_idx) {
       if(curr_idx == n)
           return 0;
        
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || predecessor(words[prev_idx], words[curr_idx]))
            taken = 1 + lis(words, curr_idx, curr_idx+1);
        
        int not_taken = lis(words, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            t[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);
            
    }
    
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        n = words.size();
        sort(begin(words), end(words), myFunction); //You can select pairs in any order.
        return lis(words, -1, 0);
    }
};


//Approach-2 (Using Simple LIS Bottom Up) - We sort it in the beginning to get words ordered in ascending order based on length
//T.C : O(n*n*n)
class Solution {
public:
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(m >= n || n-m != 1)
            return false;
        
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
    
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words), end(words), myFunction); //You can select pairs in any order.
        
        vector<int> t(n, 1);
        int maxL = 1;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                
                if(predecessor(words[j], words[i])) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
        
    }
};
