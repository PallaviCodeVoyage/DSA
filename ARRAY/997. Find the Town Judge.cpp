app1:
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);
        vector<int> trustedByOthers(n + 1, 0);

        for (const auto& t : trust) {
            int a = t[0], b = t[1];
            trustedByOthers[a]++;
            trustCount[b]++;
        }

        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1 && trustedByOthers[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
app2:
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n + 1, 0);

        for (const auto& t : trust) {
            int a = t[0], b = t[1];
            trustScore[a]--; // a trusts someone, so decrement aisa krne se i am taking the chances of that being close or equal to n-1 and thus cannot be a town judge
            trustScore[b]++; // b is trusted, so increment
        }

        for (int i = 1; i <= n; i++) {
            if (trustScore[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};
