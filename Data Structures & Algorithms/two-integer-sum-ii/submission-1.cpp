class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            int key = target - numbers[i];

            int l = i + 1;
            int h = numbers.size() - 1;
            while(l <= h) {
                int mid = l + (h - l) / 2;
                if(numbers[mid] == key) {
                    return {i + 1, mid + 1};
                }
                else if(numbers[mid] < key) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
        }
        
        return {};
    }
};
