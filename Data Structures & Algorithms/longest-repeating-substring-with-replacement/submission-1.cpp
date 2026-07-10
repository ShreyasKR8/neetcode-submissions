// brute force to understand the problem
class Solution {
public:
    int characterReplacement(string s, int k) {
        int resLength = 0;
        unordered_map<char, int> freqMap;
        int maxF = 0;
        int l = 0, r = 0;

        while(r < s.size()) {
            freqMap[s[r]]++;
            maxF = max(maxF, freqMap[s[r]]);
            while((r - l + 1) - maxF > k) {
                freqMap[s[l]]--;
                l++;
            }
            resLength = max(resLength, r - l + 1);
            r++;
        }
        
        return resLength;
    }
};
