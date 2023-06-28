/*
状态定义：
dp[i]：集合为i时，能获得的最小不兼容性
*/
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n=nums.size();
        k=n/k;//被划分成k组集合，每组集合有n/k个元素，这里直接令k=n/k
        sort(nums.begin(),nums.end());
        vector<int> dp(1<<n,1e9),invalid;
        dp[0]=0;
        for(int i=0;i<n;){//预处理，记录有相同元素的非法状态
            int st=0,j=i;
            while(j<n&&nums[j]==nums[i]){
                st|=(1<<j);
                j++;
            }
            if(__builtin_popcount(st)>1) invalid.push_back(st);
            i=j;
        }
        auto check=[&](int st){
            for(auto &t:invalid){
                if(__builtin_popcount(st&t)>1) return false;
            }
            return true;
        };
        for(int i=1;i<(1<<n);i++){
            int c=__builtin_popcount(i);//枚举集合
            if(c%k) continue;//不能被均分为若干个大小都为k的集合
            for(int j=i;j;j=(j-1)&i){//枚举子集
                if(__builtin_popcount(j)!=k) continue;//该子集大小不为k
                if(!check(j)) continue;//该子集中存在相同元素
                int mn=100,mx=0;
                for(int x=0;x<n;x++){
                    if(j&(1<<x)){
                        mn=min(mn,nums[x]);
                        mx=max(mx,nums[x]);
                    }
                }
                dp[i]=min(dp[i],dp[i^j]+mx-mn);//状态转移
            }
        }
        return dp.back()==1e9?-1:dp.back();
    }
};
