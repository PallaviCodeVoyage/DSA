class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s=students.size();
        int count0=0;
        int count1=0;
        int sa=s;
        for(int ss:students)
        {
            (ss==0)?count0++:count1++;
        }
        for(int sand:sandwiches)
        {
            if(sand==0&&count0>0)
            {
                count0--;
            }
            else if(sand==1&&count1>0)
            {
                count1--;
            }
            else
            {
                break;
            }
        }
        return count0+count1;

        
    }
};/O(N)
