/*
2566简单版，可暴力模拟
*/
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& a) {
        long long ans=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            long long cur=a[i],mx=a[i];
            for(int j=i-1;j>=0;j--){
                mx=min(1LL*a[j],mx);
                cur+=mx;
            }
            mx=a[i];
            for(int j=i+1;j<n;j++){
                mx=min(1LL*a[j],mx);
                cur+=mx;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};
