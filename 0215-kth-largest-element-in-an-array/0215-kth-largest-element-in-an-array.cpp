class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //    sort(nums.begin(),nums.end());
    //    return nums[nums.size()-k];
        priority_queue<int> q;
        for(auto i: nums){
            q.push(i);
        }
        for(int i=1;i<k;i++){
            q.pop();
        }
        return q.top();
    }
};