class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        // Check for all possible rotations (90, 180, and 270 degrees clockwise)
        for (int k = 0; k < 4; ++k) {
            if (mat == target) {
                return true; // If mat matches target, return true
            }
            rotate(mat); // Rotate mat by 90 degrees clockwise
        }
        
        return false; // If no rotation matches target, return false
    }
    
private:
    // Function to rotate the matrix 90 degrees clockwise
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        // Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};
//transpose nd reversal of each row means rotation in 90 degree and repetition will result in rotation in 180,270 degree 
