class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = 0;
        int e = nums.size();
        int d = k%e;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+d);
        reverse(nums.begin()+d,nums.end());
    }
};