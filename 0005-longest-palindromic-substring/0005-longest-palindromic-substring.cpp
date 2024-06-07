class Solution {
public:
    string expandAroundCenter(string s,int left,int right){
        while(left>=0 && right<s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size()==1) return s;

        string longest;
        for(int i=0;i<s.length();i++){
            // odd length palindronme
            string oddPalindrome  = expandAroundCenter(s,i,i);
            if(oddPalindrome.length()> longest.length()){
                longest = oddPalindrome ;
            }

            // even length palindrome
            string evenPalindrome = expandAroundCenter(s,i,i+1);
            if(evenPalindrome.length()>longest.length()){
                longest = evenPalindrome;
            }
        }
        return longest;
    }
};