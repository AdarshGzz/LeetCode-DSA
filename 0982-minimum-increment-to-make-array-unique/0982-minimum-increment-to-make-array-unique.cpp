class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int numTracker = 0;
        int minIncreament = 0;
        for(int num: nums){
            numTracker = max(numTracker,num);
            minIncreament += numTracker - num;
            numTracker += 1;
        }
        return minIncreament;
    }
};