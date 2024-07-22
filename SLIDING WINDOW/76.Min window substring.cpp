

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        } 
        
        unordered_map<char, int> m;
        for (auto f : t) {
            m[f]++;
        }
        
        int countreq = t.length();
        int i = 0;
        int j = 0;
        int start = 0;
        int minwindow = INT_MAX;
        int ss = s.length();
        
        while (j < ss) {
            if (m.find(s[j]) != m.end() && m[s[j]] > 0) {
                countreq--;
            }
            
            if (m.find(s[j]) != m.end()) {
                m[s[j]]--;
            }
            
            while (countreq == 0) {
                if (j - i + 1 < minwindow) {
                    minwindow = j - i + 1;
                    start = i;
                }
                
                if (m.find(s[i]) != m.end()) {
                    m[s[i]]++;
                    if (m[s[i]] > 0) {
                        countreq++;
                    }
                }
                
                i++;
            }

            j++;
        }
        
        return (minwindow == INT_MAX) ? "" : s.substr(start, minwindow);
    }
};
