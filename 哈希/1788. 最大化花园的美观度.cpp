/*
前缀和s：只记录前缀中所有的非负元素和
对于每一个美观值作为端点的时候，基于贪心，希望它两端点之间的花束尽可能多
因此用哈希表记录下每个美观值最左侧和最右侧的花束位置

枚举所有美观值p右端点的值r，则以美观值p的花束为端点的最大美观度为s[r]-s[l-1]+min(0,p)*2，因为端点可能是负数，而前缀和中不保存负数所以这里要加上min(0,p)*2
*/
class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        int n=flowers.size();
        vector<int> s(n+1);
        unordered_map<int,int> L,R;
        for(int i=0;i<n;i++){
            s[i+1]=s[i]+max(flowers[i],0);
            if(L.count(flowers[i])) R[flowers[i]]=i+1;
            else L[flowers[i]]=i+1;
        }
        int ans=-1e9;
        for(auto &[p,r]:R){
            ans=max(ans,s[r]-s[L[p]-1]+min(0,p)*2);
        }
        return ans;
    }
};
