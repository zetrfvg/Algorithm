/*
单调栈，对于元素x，找到其左右两端第一个比它大的元素的位置，统计贡献即可
*/
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& a) {
        int n=a.size();
        long long ans=0;
        vector<long long> pre(n+1),suf(n+1);
        stack<pair<int,int>> st;
        long long cur=0;
        for(int i=0;i<n;i++){
            cur+=a[i];
            int cnt=1;
            while(!st.empty()&&st.top().first>=a[i]){
                cur-=1LL*(st.top().first-a[i])*st.top().second;
                cnt+=st.top().second;
                st.pop();
            }
            st.push({a[i],cnt});
            pre[i+1]=cur;
        }
        cur=0;
        while(!st.empty()) st.pop();
        for(int i=n-1;~i;i--){
            cur+=a[i];
            int cnt=1;
            while(!st.empty()&&st.top().first>=a[i]){
                cur-=1LL*(st.top().first-a[i])*st.top().second;
                cnt+=st.top().second;
                st.pop();
            }
            st.push({a[i],cnt});
            suf[i]=cur;
        }
        for(int i=0;i<n;i++){
            ans=max(ans,pre[i+1]+suf[i]-a[i]);
            //cout<<pre[i+1]<<" "<<suf[i]<<" ";
        }
        return ans;
    }
};
