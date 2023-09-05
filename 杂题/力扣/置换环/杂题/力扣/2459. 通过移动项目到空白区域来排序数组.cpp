/*
找到所有的置换环(长度大于1)
如果0在环上，则该环的操作次数为环长减1
否则需要引入一个0来才能操作这个环上的元素，操作次数为环长加1
两种排序情况取较小即可
*/
class Solution {
public:
    int sortArray(vector<int>& nums) {
        int n=nums.size();
        auto fun=[&](vector<int>& p,vector<int> num){
            vector<int> vis(n);
            int res=0;
            for(int i=0;i<n;i++){
                if(p[num[i]]==i) continue;
                if(!vis[num[i]]){
                    bool flag=vis[0];
                    while(p[num[i]]!=i){
                        vis[num[i]]=1;
                        swap(num[p[num[i]]],num[i]);
                    }
                    vis[num[i]]=1;
                    if(flag==vis[0]) res++;
                    else res--;
                }
            }
            for(int i=0;i<n;i++) if(vis[i]) res++;
            return res;
        };
        vector<int> p(n);
        for(int i=1;i<n;i++) p[i]=i;
        int ans=fun(p,nums);
        for(int i=0;i<n-1;i++) p[i+1]=i;
        p[0]=n-1;
        ans=min(ans,fun(p,nums));
        return ans;
    }
};
