//bad day, kms
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }

        vector<int>s1Count (26, 0);
        vector<int>s2Count (26, 0);
        int matches = 0;
        int l = 0;

        // the first window
        for(int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        // continue for the next windows
        for(int r = s1.length(); r < s2.length(); r++) {
            if(matches == 26) {
                return true;
            }

            // expand the window on right
            int index = s2[r] - 'a';
            s2Count[index]++;
            if(s1Count[index] == s2Count[index]) {
                matches++;
            }
            else if(s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            //shrink the window from left
            index = s2[l] - 'a';
            s2Count[index]--;
            if(s1Count[index] == s2Count[index]) {
                matches++;
            }
            else if(s1Count[index] - 1 == s2Count[index]){
                matches--;
            }

            l++;
        }

        return matches == 26;
    }
};
