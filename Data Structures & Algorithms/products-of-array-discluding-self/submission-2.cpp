class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res (n);

        int prefix = 1, suffix = 1;

        res[0] = 1;
        cout<<res[0]<<",";
        for(int i = 1; i < n; i++) {
            prefix *= nums[i - 1];
            res[i] = prefix;
            cout<<res[i]<<",";
        }

        // res[n - 1] = 
        for(int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            res[i] = res[i] * suffix;
        }

        return res;
    }
};
