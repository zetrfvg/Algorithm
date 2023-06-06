/*
每一行元素用一个p进制的数表示，并对1e9+7取模，用一个哈希表来记录每个p进制数出现的次数
枚举每一列的p进制数，在哈希表中查询，累加答案即可
*/
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int p=100019;
        const int mod=1e9+7;
        unordered_map<int,int> g;
        int n=grid.size();
        for(int i=0;i<n;i++){
            int hash=1;
            for(int j=0;j<n;j++){
                hash=(1LL*hash*p+grid[i][j])%mod;
            }
            g[hash]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int hash=1;
            for(int j=0;j<n;j++){
                hash=(1LL*hash*p+grid[j][i])%mod;
            }
            ans+=g[hash];
        }
        return ans;
    }
};
