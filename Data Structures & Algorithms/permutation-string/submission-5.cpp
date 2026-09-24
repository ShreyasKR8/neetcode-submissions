class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int l = 0, r = 0;

        for( ; r < s1.length(); r++) {
            freq1[s1[r] - 'a']++;
            freq2[s2[r] - 'a']++;
        }

        if(freq1 == freq2) {
            return true;
        }

        for( ; r < s2.length(); r++) {
            freq2[s2[r] - 'a']++;
            freq2[s2[l] - 'a']--;
            l++;


            if(freq1 == freq2) {
                return true;
            }

        }

        return false;
    }
};
