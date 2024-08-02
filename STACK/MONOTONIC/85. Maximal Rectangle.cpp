class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; ++i) {
            // Update the heights vector based on the current row
            for (int j = 0; j < n; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            //yha pe jo ye 0 derre hain hum ye islia dia hain so that to reset it to 0 and break teh stretch of 1
            // Calculate the maximum area for the current row
            maxArea = max(maxArea, maxRectangleArea(heights));
        }
        
        return maxArea;
    }
    
private:
    int maxRectangleArea(const vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];
            while (!stk.empty() && h < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }
        
        return maxArea;
    }
};
