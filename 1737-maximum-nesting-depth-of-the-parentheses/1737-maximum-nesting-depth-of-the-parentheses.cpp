class Solution {
public:
    int maxDepth(string s) {
 int count = 0;
        int maxCount = 0;

        for (char i : s) {
            if (i == '(') {
                count++;
                maxCount = max(maxCount,count);
            } else if (i == ')') {
                count--;
            }
        }

        return maxCount;
    }
};