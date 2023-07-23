/*
单调栈应用，维护一个单调递减的栈
元素出栈时，其能接到的雨水量为左右两边高度的最小值减去出栈的元素值乘上区间长
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            int h=0;
            while(!st.empty()&&height[st.top()]<=height[i]){
                h=height[st.top()];
                st.pop();
                if(!st.empty()) ans+=(min(height[i],height[st.top()])-h)*(i-st.top()-1);
            }
            st.push(i);
        }
        return ans;
    }
};
