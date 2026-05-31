class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int longest = 0;

        for(int num : nums) {
            s.insert(num);
        }

        for(int num : nums) {
            int length = 0;

            //check if the number is the start of a sequence
            if(!s.count(num - 1)) {
                length = 1;

                //check if consecutive numbers exist using num + length
                while(s.count(num + length)) {
                    length++;
                }
            }
            
            if(longest < length) {
                longest = length;
            }
        }

        return longest;
    }
};
