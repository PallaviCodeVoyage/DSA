class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> left_b(n), r_b(n);
        stack<int> st;

        // Fill left_b array
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left_b[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) {
            st.pop();
        }

        // Fill r_b array
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            r_b[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        // Calculate maximum area
        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            int width = r_b[i] - left_b[i] + 1;
            max_area = max(max_area, heights[i] * width);
        }

        return max_area;
    }
};
/***using boundary array approach*/
/**brute**/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            int min_height = heights[i];
            for (int j = i; j < n; ++j) {
                min_height = min(min_height, heights[j]);
                int width = j - i + 1;
                max_area = max(max_area, min_height * width);
            }
        }

        return max_area;
    }
};

