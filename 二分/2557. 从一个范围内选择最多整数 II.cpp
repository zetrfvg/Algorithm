/*
直接二分答案，复杂度O(mlogn)，m为banned数组长度
*/
class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        int l=1,r=n;
        long long sum;
        unordered_set<int> st(banned.begin(),banned.end());
        while(l<r){
            int m=(l+r+1)>>1;
            sum=(1LL+m)*m/2;
            for(auto x:st) if(x<=m) sum-=x;
            if(sum<=maxSum) l=m;
            else r=m-1;
        }
        int ans=l;
        for(auto x:st) if(x<=l) ans--;
        return ans;
    }
};
