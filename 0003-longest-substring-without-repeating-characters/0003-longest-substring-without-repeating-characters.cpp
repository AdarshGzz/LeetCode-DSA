class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int maxSub = INT_MIN;
        int l = 0;
        unordered_set<int> set;
        for (int r = 0; r < s.length(); r++) {
            if (set.find(s[r]) != set.end()) {
                while (l < r && set.find(s[r]) != set.end()) {
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            maxSub = max(r - l + 1, maxSub);
        }
        return maxSub;
    }
};