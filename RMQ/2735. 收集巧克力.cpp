/*
预处理出巧克力的最小值st表
枚举修改的区间长度
再枚举所有巧克力，用区间长度中的最小值为代价来购买这个巧克力
*/
class Solution {
public:
    int st[2010][16];
    long long minCost(vector<int>& nums, int x) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        for(int i=0;i<2*n;i++) st[i+1][0]=a[i];
        int p=log2(n);
        for(int i=1;i<=p;i++){
            for(int j=1;j+(1<<i)<=2*n+1;j++){
                st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
            }
        }
        long long ans=1e16;
        for(int d=1;d<=n;d++){
            long long cur=1LL*(d-1)*x;
            int p=log2(d);
            for(int i=0;i<n;i++){
                cur+=min(st[i+1][p],st[i+d-(1<<p)+1][p]);
            }
            ans=min(ans,cur);
        }
        return ans;
    }
};
