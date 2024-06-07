class Solution {
public:
    int maxArea(vector<int>& height) {
        // find max 
        // if area in greater than return ans;
        if(height.size()<2){
            return 0;
        }
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left<right){
            int currH = min(height[left],height[right]);
            int currW = right-left;
            int area = currH * currW;
            maxArea = max(area,maxArea);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};