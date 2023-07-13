/*
利用单调栈可以找到每个元素nums[i]后继的第一个小于它的元素nums[j]，则以nums[i]为左端点合法的子数组有j-i个，累加答案即可
*/
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        nums.push_back(-1);//哨兵
        int ans=0;
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[i]<nums[st.top()]){
                ans+=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
