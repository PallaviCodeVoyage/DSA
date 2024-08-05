class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int asteroid : asteroids) {
            if (asteroid > 0) { // Asteroid moving from left to right
                s.push(asteroid);
            } else { // Asteroid moving from right to left
                while (!s.empty() && s.top() > 0 && s.top() < -asteroid) {
                    s.pop(); // Destroy the asteroid moving from left to right
                }
                if (s.empty() || s.top() < 0) {
                    s.push(asteroid); // Add the asteroid moving from right to left
                } else if (s.top() == -asteroid) {
                    s.pop(); // Destroy both asteroids if they are of equal size
                }
            }
        }
        // Construct the result array from the remaining elements in the stack
        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }
        return result;
    }
};
