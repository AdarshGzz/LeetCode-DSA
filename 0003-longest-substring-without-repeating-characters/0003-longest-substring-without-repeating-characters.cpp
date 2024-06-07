class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       if(n==0){
        return 0;
       }
       int msl = 0;
       int l = 0;
       unordered_set<int> set;
       for(int r=0;r<n;r++){
        if(set.find(s[r]) != set.end()){
            while(l<r && set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
        }
        set.insert(s[r]);
        msl = max(r-l+1,msl);
       }
       return msl;
    }
};