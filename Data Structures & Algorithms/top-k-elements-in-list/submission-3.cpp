//practice
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freqMap;
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> minHeap;

        vector<int> res;

        for(int num : nums) {
            freqMap[num]++;
        }

        for(auto itr : freqMap) {
            minHeap.push(make_pair(itr.second, itr.first));
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        for(int i = 0; i < k; i++) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
