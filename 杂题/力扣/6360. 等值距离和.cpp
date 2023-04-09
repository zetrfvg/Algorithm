/*
前后缀来枚举当前元素a[i]，之前有多少个元素等于a[i]，之后有多少个元素等于a[i]
边统计答案边更新前后缀
*/
class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        int n=a.size();
        vector<long long> ans(n);
        map<int,pair<long long,long long>> pre,suf;
        for(int i=0;i<n;i++){
            suf[a[i]].first++;
            suf[a[i]].second+=i;
        }
        for(int i=0;i<n;i++){
            suf[a[i]].first--;
            suf[a[i]].second-=i;
            auto [x,y]=pre[a[i]];
            auto [w,z]=suf[a[i]];
            ans[i]=x*i-y+z-w*i;
            pre[a[i]].first++;
            pre[a[i]].second+=i;
        }
        return ans;
    }
};
