class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;
        int l = 0, r = k - 1;

        for(int i = l; i <= r; i++) {
            maxHeap.push({nums[i], i});
        }

        result.push_back(maxHeap.top().first);

        l++; r++;

        while(r < nums.size()) {
            maxHeap.push({nums[r], r});

            while(maxHeap.top().second < l) {
                maxHeap.pop();
            }

            result.push_back(maxHeap.top().first);

            l++; r++;
        }

        return result;
    }
};
