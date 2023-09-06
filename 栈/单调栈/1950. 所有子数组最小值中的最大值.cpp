/*
以单调栈枚举出各个元素作为子数组最小值能够到达的最远左右边界
计算答案时，用能够扩展范围更大的元素来更新扩展范围小的即可
*/
class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(st.size()>1&&nums[st.top()]>nums[i]){
                int j=st.top();
                st.pop();
                ans[i-st.top()-2]=max(ans[i-st.top()-2],nums[j]);
            }
            st.push(i);
        }
        while(st.size()>1){
            int j=st.top();
            st.pop();
            ans[n-st.top()-2]=max(ans[n-st.top()-2],nums[j]);
        }
        for(int i=n-2;~i;i--) ans[i]=max(ans[i],ans[i+1]);
        return ans;
    }
};
