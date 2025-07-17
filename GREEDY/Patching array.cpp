#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // 'miss' wo smallest number hai jo abhi tak nahi ban pa raha
        int i = 0;          // nums array ka index
        int patches = 0;    // kitne numbers patch/add kiye, yeh count rakhta hai

        while (miss <= n) {
            // Agar current array ka number chhota ya barabar hai 'miss' se,
            // to use use karke hum 'miss' tak ke numbers bana sakte hain
            if (i < nums.size() && nums[i] <= miss) {
                // is number ko use karke range badh jaayegi
                miss += nums[i];
                i++;
            } else {
                // agar current number bada hai 'miss' se,
                // to 'miss' ko hi patch karo (add karo)
                // kyunki 'miss' ko patch karke hum range ko double tak extend kar sakte hain
                miss += miss;
                patches++;  // ek patch add hua
            }
        }

        return patches; // total kitne patches ki zarurat padi
    }
};
