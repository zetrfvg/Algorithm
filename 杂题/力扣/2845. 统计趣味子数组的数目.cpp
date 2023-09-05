/*
用c来表示枚举到的前缀中a[i]%mod==k的个数，用哈希表p来记录前缀和取值的个数
对于每个a[i]为右端点，其贡献的子数组数目有p[(c-k+mod)%mod]个，表示之前的前缀和取模之后比c少k的左端点个数
*/
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& a, int mod, int k) {
        long long ans=0;
        unordered_map<int,int> p;
        int c=0;
        p[0]=1;
        for(int i=0;i<a.size();i++){
            if(a[i]%mod==k) c=(c+1)%mod;
            ans+=1LL*p[(c-k+mod)%mod];
            p[c]++;
        }
        return ans;
    }
};
