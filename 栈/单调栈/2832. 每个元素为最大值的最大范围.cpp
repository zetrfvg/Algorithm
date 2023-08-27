/*
对于每个nums[i]，求出其左右两边离它最近的大于它的元素，这是经典的单调栈使用场景
*/
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(st.size()>1&&nums[st.top()]<nums[i]){
                int j=st.top();
                st.pop();
                ans[j]=i-st.top()-1;
            }
            st.push(i);
        }
        while(st.size()>1){
            int j=st.top();
            st.pop();
            ans[j]=n-1-st.top();
        }
        return ans;
    }
};
