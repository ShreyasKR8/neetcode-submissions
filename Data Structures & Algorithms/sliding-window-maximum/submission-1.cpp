class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        int l = 0, r = k - 1;

        // Build the first k-sized window
        for(int i = l; i <= r; i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        result.push_back(nums[dq.front()]);

        l++; r++;

        // slide the window
        while(r < nums.size()) {
            // Remove max if it has gone out of the window
            if(!dq.empty() && dq.front() < l) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            //add new element
            dq.push_back(r);

            //front is always the max
            result.push_back(nums[dq.front()]);
            l++; r++;
        }

        return result;
    }
};
