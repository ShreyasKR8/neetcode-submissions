class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> result;
        int l = 0, r = k - 1;

        // Build heap for the first window
        for(int i = l; i <= r; i++) {
            heap.push({nums[i], i});
        }
        result.push_back(heap.top().first);

        //slide the window
        l++; r++;

        while(r < nums.size()) {
            heap.push({nums[r], r});

            //remove stale entries where top ele is out of window
            //why while? READ THE BOTTOM COMMENT!
            while(heap.top().second < l) {
                heap.pop();
            }

            result.push_back(heap.top().first);

            //slide the window
            l++; r++;
        }

        return result;
    }
};

// why use while if we are moving window one element at a time?
// Example: nums = [5, 10, 1, 1, 1], k = 3 
//Using while because multiple stale elements can reach the top consecutively.