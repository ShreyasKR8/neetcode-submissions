class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        int length = 1;
        unordered_set<char> charSet;
        int i = 0, j = 1;
        charSet.insert(s[i]);

        while(j < s.size()) {
            if(!charSet.contains(s[j])){
                charSet.insert(s[j]);
                length = max(length, j - i + 1);
            }
            else {
                while(s[i] != s[j]) {
                    charSet.erase(s[i]);
                    i++;
                }
                i++;
            }
            j++;
        }

        return length;

    }
};
