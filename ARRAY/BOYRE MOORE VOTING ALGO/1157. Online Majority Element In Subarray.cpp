/*class MajorityChecker {
public:
 vector<int>arr;
    MajorityChecker(vector<int>& arr) {
        this->arr=arr;
        
    }
    
    int query(int left, int right, int threshold) {
        unordered_map<int,int>mp;
        for(int i=left;i<=right;i++)
        {
            mp[arr[i]]++;

        }
        for(pair<int,int>m:mp)
        {
            if(m.second>=threshold)
            {
                return m.first;
            }
        }
        return -1;
        
    }
};*/

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
class MajorityChecker {
public:
 vector<int>arr;
    MajorityChecker(vector<int>& arr) {
        this->arr=arr;
        
    }
    
    int query(int left, int right, int threshold) {
       int cand=-1;
       int count=0;
       for(int i=left;i<=right;i++)
       {
        if(count==0)
        {
            cand=arr[i];
        }

        count+=(cand==arr[i])?1:-1;
       }
       int occ=0;
        for(int i=left;i<=right;i++)
       {
        if(cand==arr[i])
        {
            occ++;
        }
        

       
       }
       return(occ>=threshold)?cand:-1;

       
    }
};



























