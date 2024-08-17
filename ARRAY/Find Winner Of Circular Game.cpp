

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> people(n);
        for (int i = 0; i < n; ++i) {
            people[i] = i + 1;
        }

        int index = 0;
        while (people.size() > 1) {
            index = (index + k - 1) % people.size();
            people.erase(people.begin() + index);
        }

        return people[0];
    }
};
