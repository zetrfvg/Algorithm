/*
离线+三分
注意观察到性质，Bob的最优选择一定是选最小的x个巧克力和最大的y个巧克力，前者是使Bob的费用尽可能的小，后者则能够把一部分费用摊还给Alice来达到降低Bob代价的目的
容易知道这是一个单峰函数，是三分使用的场景，这里使用了开区间的写法
计算calc函数的时候需要一边回答询问一边处理前后缀的更新，于是就用到了离线的性质
预处理price的前缀和，将询问按k值升序处理，每次询问，把大于k的都加入后缀，同时更新后缀和
这样计算calc的时候就是O(1)的，整体复杂度O(qlogq+(n+q)logn)
*/
class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) {
        int n=prices.size(),sz=queries.size();
        sort(prices.begin(),prices.end());
        vector<long long> ans(sz,1e14);
        for(int i=0;i<sz;i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),greater<>());
        vector<long long> pre(n+1),suf{0};
        for(int i=0;i<n;i++) pre[i+1]=1LL*pre[i]+prices[i];
        auto calc=[&](int cnt,int m,int k){
            int i=cnt,j=m-cnt;
            return pre[i]-suf[j]+2LL*j*k;
        };
        for(auto q:queries){
            int k=q[0],m=q[1],j=q[2];
            while(pre.size()>1&&prices[pre.size()-2]>k){
                suf.push_back(suf.back()+1LL*prices[pre.size()-2]);
                pre.pop_back();
            }
            int l=max(m-(int)suf.size()+1,0),r=min((int)pre.size()-1,m);
            while(r-l>3){
                int mid=(r-l)/3;
                if(calc(l+mid,m,k)>calc(r-mid,m,k)) l+=mid;
                else r-=mid;
            }
            for(int u=l;u<=r;u++) ans[j]=min(ans[j],calc(u,m,k));
        }
        return ans;
    }
};
