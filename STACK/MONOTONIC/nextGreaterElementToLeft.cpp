#include <vector>
#include <stack>
#include <iostream>
/***monotonic decreasing**/

std::vector<int> nextGreaterElementToLeft(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> st;  // Stack to store elements directly

    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the current element is greater than
        // or equal to the element at the top of the stack
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();  // Pop the element from the stack
        }
        // If the stack is not empty, the top of the stack is the next greater
        // element to the left for the current element
        if (!st.empty()) {
            result[i] = st.top();
        }
        // Push the current element onto the stack
        st.push(nums[i]);
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 5, 2, 10, 8};  // Example input
    std::vector<int> result = nextGreaterElementToLeft(nums);  // Get the result
    
    std::cout << "Next Greater Element to the Left: ";
    for (int num : result) {
        std::cout << num << " ";  // Print the result
    }
    std::cout << std::endl;
    return 0;
}
