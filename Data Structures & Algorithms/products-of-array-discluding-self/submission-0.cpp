class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>preProduct (size, 1);
        vector<int>postProduct (size, 1);
        vector<int> res(size);

        preProduct[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            preProduct[i] = preProduct[i - 1] * nums[i - 1];
        }

        postProduct[size - 1] = 1;
        for(int i = size - 2; i >= 0; i--) {
            postProduct[i] = postProduct[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < size; i++) {
            res[i] = preProduct[i] * postProduct[i];
        }

        return res;
    }
};
