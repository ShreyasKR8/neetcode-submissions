// One-pass binary search by treating the 2D matrix as a flattened 1D array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int low = 0;
        int high = ROWS * COLS - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            //map the mid back to matrix row and col
            int row = mid / COLS;
            int col = mid % COLS;

            if(target < matrix[row][col]) {
                high = mid - 1;
            }
            else if(target > matrix[row][col]) {
                low = mid + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
