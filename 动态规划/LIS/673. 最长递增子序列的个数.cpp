/*
状态定义：
dp1[i]：以第i个元素结尾，LIS的长度
dp2[i]：以第i个元素结尾，LIS最长的序列数量
转移方程：
if(nums[i]>nums[j]){
    if(dp1[j]+1>dp1[i]){
        dp1[i]=dp1[j]+1;
        dp2[i]=dp2[j];
    }else if(dp1[j]+1==dp1[i]){
        dp2[i]+=dp2[j];
    }
}else{
    dp1[i]=dp2[i]=1;
}

时间复杂度：O(n^2)
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n),dp2(n);
        int mxlen=0;
        for(int i=0;i<n;i++){
            dp1[i]=dp2[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp1[j]+1>dp1[i]){
                        dp1[i]=dp1[j]+1;
                        dp2[i]=dp2[j];
                    }else if(dp1[j]+1==dp1[i]){
                        dp2[i]+=dp2[j];
                    }
                }
            }
            mxlen=max(mxlen,dp1[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp1[i]==mxlen){
                ans+=dp2[i];
            }
        }
        return ans;
    }
};


/*
贪心+二分+树状数组
LIS的贪心算法维护了一个LIS序列
这里用树状数组来维护LIS的最大值及最大值个数
首先对数组进行离散化操作
随后当查询元素x时我们在树状数组中找到严格小于它的元素的LIS的长度及个数

时间复杂度：O(nlogn)
*/
class Solution {
public:
    int n;
    int tr[2010][2];
    int lowbit(int x){
        return x&-x;
    }
    void add(int u,int len,int cnt){
        for(int i=u;i<=n;i+=lowbit(i)){
            if(len==tr[i][0]){
                tr[i][1]+=cnt;
            }else if(len>tr[i][0]){
                tr[i][0]=len;
                tr[i][1]=cnt;
            }
        }
    }
    pair<int,int> query(int u){
        int len=0,res=0;
        for(int i=u;i;i-=lowbit(i)){
            if(len==tr[i][0]){
                res+=tr[i][1];
            }else if(len<tr[i][0]){
                len=tr[i][0];
                res=tr[i][1];
            }
        }
        return {len,res};
    }
    int findNumberOfLIS(vector<int>& nums) {
        n=nums.size();
        auto b=nums;
        sort(b.begin(),b.end());
        b.resize(unique(b.begin(),b.end())-b.begin());
        auto get=[&](int x){
            return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
        };
        for(int i=0;i<n;i++){
            int x=get(nums[i]);
            auto [len,cnt]=query(x-1);
            add(x,len+1,max(1,cnt));
        }
        return query(n).second;
    }
};
