class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        // Start from the end of the string and find the first odd digit
        for (int i = num.size() - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            if (digit % 2 != 0) {
                index = i + 1;
                break;
            }
        }
        
        // If an odd digit is found, return the substring from the start to the found index
        if (index != -1) {
            return num.substr(0, index);
        }
        
        // If no odd digit is found, return an empty string
        return "";
    }
};