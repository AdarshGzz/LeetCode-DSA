class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0;
        return helper(s,i);
    }

    string helper(string& s,int& i) {
        string result;

        while (i < s.length()) {
            if (s[i] == ')') {
                i++;
                reverse(result.begin(), result.end());
                return result;
            } else if (s[i] == '(') {
                i++;
                string st = helper(s,i);
                result += st;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};