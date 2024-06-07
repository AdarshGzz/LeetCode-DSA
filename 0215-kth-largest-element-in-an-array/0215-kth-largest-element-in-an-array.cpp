class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> heap;
       for(auto i: nums){
        heap.push(i);
       }
       for(int i =1;i<k;i++){
        heap.pop();
       }
       return heap.top();
    }
};