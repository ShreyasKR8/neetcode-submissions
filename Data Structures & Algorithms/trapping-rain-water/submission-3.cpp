//Updated to use inclusive prefix/suffix maximum arrays, 
// removing the need for clamping and aligning with the standard O(n) solution.
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int>prefixMax (size, 0);
        vector<int>suffixMax (size, 0);
        int area = 0;

        //pre compute left max
        prefixMax[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        // pre compute right max
        suffixMax[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        for(int i = 0; i < size; i++) {
            area += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        
        return area;
    }
};