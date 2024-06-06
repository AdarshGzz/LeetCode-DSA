class Solution {
public:
    int myAtoi(string s) {
       int i = 0;
    int n = s.size();
    
    // Step 1: Ignore leading whitespace
    while (i < n && isspace(s[i])) {
        i++;
    }
    
    // Step 2: Check for sign
    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Step 3: Read the integer part
    long long result = 0;
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        // Check for overflow and underflow
        if (result * sign >= INT_MAX) {
            return INT_MAX;
        } else if (result * sign <= INT_MIN) {
            return INT_MIN;
        }
        i++;
    }
    
    return (result * sign);

    }
};