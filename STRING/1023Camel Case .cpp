class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> results;
        for (const string& query : queries) {
            results.push_back(isMatchBruteForce(query, pattern));
        }
        return results;
    }

private:
    bool isMatchBruteForce(const string& query, const string& pattern) {
        int i = 0, j = 0;
        
        while (i < query.size() && j < pattern.size()) {
            if (query[i] == pattern[j]) {
                j++;
            } else if (isupper(query[i])) {
                return false;
            }
            i++;
        }
        
        // If we have matched the entire pattern
        if (j == pattern.size()) {
            // Check if there are any remaining uppercase letters in query
            while (i < query.size()) {
                if (isupper(query[i])) return false;
                i++;
            }
            return true;
        }
        
        return false;
    }
};
//point 1 we a pattern needs o be matched with carry by adding small case alphabets
//oint 2 if there is any character in querry which is not in pat so it needs to be in lower case as we can add only lower case
//alphabets in pat to make it match with querry
