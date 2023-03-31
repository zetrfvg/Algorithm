/*
因为求最大异或值，很自然想到用01-Trie来维护这个nums数组
离线处理所有询问，把所有询问按m从大到小排序，按m的大小来回答每个询问
对于每一个询问queries[i]，需要把大于mi的元素从字典树中删除，然后再在字典树中找最大的异或值即可
*/
class Solution {
public:
    static const int N=1e5+5;
    int tr[31*N][2],cnt[31*N],idx=0;
    void insert(int u,int k){
        int p=0;
        for(int i=30;~i;i--){
            int j=(u>>i)&1;
            if(!tr[p][j]) tr[p][j]=++idx;
            p=tr[p][j];
            cnt[p]+=k;
        }
    }
    int query(int u){
        int p=0,res=0;
        for(int i=30;~i;i--){
            int j=(u>>i)&1;
            if(cnt[tr[p][!j]]){
                p=tr[p][!j];
                res|=(1<<i);
            }else p=tr[p][j];
        }
        return res;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        memset(tr,0,sizeof tr);
        memset(cnt,0,sizeof cnt);
        sort(nums.begin(),nums.end());
        int n=nums.size(),m=queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),[](const auto &a,const auto &b){
            return a[1]>b[1];
        });
        for(auto &c:nums) insert(c,1);
        for(int r=n-1,i=0;i<m;i++){
            int x=queries[i][0],s=queries[i][1],j=queries[i][2];
            while(r>=0&&nums[r]>s) insert(nums[r--],-1);
            if(r>=0) ans[j]=query(x);
            else ans[j]=-1;
        }
        return ans;
    }
};
