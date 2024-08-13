/*class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string>uni;
        int n=arr.size();
        int notu=1;
        for(int i=0;i<n;i++)
        {
            notu=1;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                else if(arr[i]==arr[j])
                {
                    notu=0;
                    break;
                }

            }
            if(notu==0)
            {
                continue;
            }
            else
            {
                uni.push_back(arr[i]);
            }
        }

        return (uni.size()<k)?"":uni[k-1];
    }
};

*/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freqMap;
        vector<string> uniqueStrings;

        // Count the frequency of each string
        for (const string& s : arr) {
            freqMap[s]++;
        }

        // Collect strings that appear only once
        for (const string& s : arr) {
            if (freqMap[s] == 1) {
                uniqueStrings.push_back(s);
            }
        }

        // Return the k-th distinct string if it exists
        return (uniqueStrings.size() < k) ? "" : uniqueStrings[k - 1];
    }
};
