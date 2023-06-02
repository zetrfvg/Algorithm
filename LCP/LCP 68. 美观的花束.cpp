/*
双指针枚举右端点最长的合法花束子数组，那么以当前元素为右端点的合法的花束的选法数和区间长相等，累计答案即可
*/
class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        const int mod=1e9+7;
        unordered_map<int,int> g;
        long long ans=0;
        int n=flowers.size();
        for(int l=0,r=0;r<n;r++){
            g[flowers[r]]++;
            while(g[flowers[r]]>cnt) g[flowers[l++]]--;
            ans=ans+1LL*(r-l+1)%mod;
        }
        return ans;
    }
};
