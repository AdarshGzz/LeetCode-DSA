class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0){
            return 0;
        }
        unordered_map<int,int> charCount;
        int maxCount =0,maxLength =0;
        int l = 0;

        for(int r=0;r<s.length();r++){
            charCount[s[r]]++;
            maxCount = max(maxCount,charCount[s[r]]);

            while((r-l+1)-maxCount > k){
                charCount[s[l]]--;
                l++;
            }
            maxLength = max(maxLength,r-l+1);
        }
        return maxLength;
    }
};