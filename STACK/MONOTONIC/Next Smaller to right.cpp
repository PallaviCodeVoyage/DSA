#include <vector>
#include <stack>
#include <iostream>

std::vector<int> nextSmallerElementToRight(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 5, 2, 10, 8};
    std::vector<int> result = nextSmallerElementToRight(nums);
    
    std::cout << "Next Smaller Element to the Right: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
