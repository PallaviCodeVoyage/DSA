#include <vector>
#include <stack>
#include <iostream>

std::vector<int> nextSmallerElementToLeft(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = nums[st.top()];
        }
        st.push(i);
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 5, 2, 10, 8};
    std::vector<int> result = nextSmallerElementToLeft(nums);
    
    std::cout << "Next Smaller Element to the Left: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
