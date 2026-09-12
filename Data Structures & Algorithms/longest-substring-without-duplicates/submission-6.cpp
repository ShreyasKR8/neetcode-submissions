//practice
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }

        int longestLength = 0;
        int i = 0, j = 0;
        unordered_set<char> windowChars;

        while(j < s.size()) {
            //can just eliminate the if-else since we have to insert() in both cases.
            // but keeping it for clarity
            if(!windowChars.contains(s[j])) {
                windowChars.insert(s[j]);
            }
            else {
                while(windowChars.contains(s[j])) {
                    windowChars.erase(s[i]);
                    i++;
                }
                windowChars.insert(s[j]);
            }
            longestLength = max(longestLength, j - i + 1);
            j++;
        }

        return longestLength;
    }
};
