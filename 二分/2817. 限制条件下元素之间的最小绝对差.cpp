/*
枚举nums[i]，用一个multiset来维护abs(i-j)>=x的所有nums[j]
每次枚举，在multiset中二分找到离nums[i]最近的两个元素，来更新答案即可
枚举完后，还需要更新multiset中的元素
*/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if(!x) return 0;
        multiset<int> st;
        int n=nums.size();
        for(int i=x;i<n;i++) st.insert(nums[i]);
        int ans=1e9;
        for(int i=0;i<n;i++){
            auto p=st.upper_bound(nums[i]);
            if(p!=st.end()) ans=min(ans,abs(*p-nums[i]));
            if(p!=st.begin()){
                p--;
                ans=min(ans,abs(*p-nums[i]));
            }
            if(i+x<n) st.erase(st.find(nums[i+x]));
            if(i-x+1>=0) st.insert(nums[i-x+1]);
        }
        return ans;
    }
};
