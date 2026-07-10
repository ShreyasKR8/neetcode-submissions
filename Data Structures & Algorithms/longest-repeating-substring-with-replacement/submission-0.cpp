// brute force to understand the problem
class Solution {
public:
    int characterReplacement(string s, int k) {
        int resLength = 0;

        for(int i = 0; i < s.size(); i++) {
            unordered_map<char, int> freqMap;
            int maxF = 0;
            for(int j = i; j < s.size(); j++) {
                freqMap[s[j]]++;
                maxF = max(maxF, freqMap[s[j]]);
                if(((j - i + 1) - maxF) <= k) {
                    resLength = max(resLength, (j - i + 1));
                }
            }
        }
        
        return resLength;
    }
};
