/*
双指针，从左右两端开始枚举
每次选择高度更小的一端移动
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,l=0,r=height.size()-1;
        while(l<r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            height[l]>height[r]?r--:l++;
        }
        return ans;
    }
};
