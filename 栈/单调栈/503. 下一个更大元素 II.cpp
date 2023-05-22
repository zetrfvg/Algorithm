/*
因为题目要求的查找呈环状
因此破环成链，把原数组拷贝到[n,2*n-1]上
然后就是单调栈的经典应用场景
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i=0;i<2*n;i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            if(i<n) st.push(i);
        }
        while(!st.empty()){
            ans[st.top()]=-1;
            st.pop();
        }
        return ans;
    }
};
