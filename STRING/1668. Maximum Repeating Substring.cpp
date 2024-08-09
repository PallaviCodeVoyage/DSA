class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        string wtf=word;
        int m = word.size();
        int count = 0;
        while(true)
        {
            if(sequence.find(wtf)!=string::npos)
            {
                count++;
                wtf+=word;
            }
            else
            {
                break;
            }
        }
        return count;
        
      
    }
};
