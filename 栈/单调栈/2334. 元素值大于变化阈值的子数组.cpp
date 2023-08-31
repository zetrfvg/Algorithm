/*
对于每个nums[i]，我们用单调栈求出离它最近的两个比它小的元素的位置l,r
如果threshold<nums[i]*(r-l-1)，就说明区间[l+1,r-1]是满足答案的区间
*/
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.size()>1&&nums[i]<nums[st.top()]){
                int j=st.top();
                st.pop();
                if(threshold<1LL*nums[j]*(i-st.top()-1)) return i-st.top()-1;
            }
            st.push(i);
        }
        while(st.size()>1){
            int j=st.top();
            st.pop();
            if(threshold<1LL*nums[j]*(n-st.top()-1)) return n-st.top()-1;
        }
        return -1;
    }
};
