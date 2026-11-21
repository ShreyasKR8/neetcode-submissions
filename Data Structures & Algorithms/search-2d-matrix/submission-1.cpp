class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int high = matrix.size() - 1; //m
        int low = 0;

        // find the nearest row in which element can exist
        while(low <= high) {
            cout<<high;
            int mid = low + (high - low) / 2;
            if(target < matrix[mid][0]) {
                high = mid - 1;
            } 
            else if(target > matrix[mid][0]) {
                low = mid + 1;
            }
            else {
                return true;
            }
        }

        int i = low - 1; //store the row index
        if(i < 0) { //this shi got me - matrix=[[1]] target=0
            return false;
        }

        low = 0;
        high = matrix[0].size() - 1; //n
        cout<<high;
        // search the ele inside the nearest row
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(target < matrix[i][mid]) {
                high = mid - 1;
            } 
            else if(target > matrix[i][mid]) {
                low = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
