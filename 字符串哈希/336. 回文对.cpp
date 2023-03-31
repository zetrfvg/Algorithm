/*
计算每个字符串的正向哈希值hash和反向哈希值invhash
暴力枚举任意两个串i，j如果word[i]+word[j]是回文串，则说明这个合成串的正反向哈希值相等
计算它的哈希值：
正向值：hash[i]*fac[len[j]]+hash[j]
反向值：invhash[j]*fac[len[i]]+invhash[i]
其中len表示该串的长度

（目前此题字符串哈希已超时无法通过，得用Manacher或者字典树）
*/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int base=13331;
        const int mod=1e9+7;
        int n=words.size();
        vector<int> fac(310);
        vector<int> hash(n),invhash(n);
        vector<int> len(n);
        fac[0]=1;
        for(int i=1;i<=300;i++) fac[i]=(1LL*fac[i-1]*base)%mod;
        for(int i=0;i<n;i++){
            int m=words[i].size();
            len[i]=m;
            int v=0;
            for(int j=0;j<m;j++){
                v=(1LL*v*base+words[i][j]-'a')%mod;
            }
            hash[i]=v,v=0;
            for(int j=m-1;j>=0;j--){
                v=(1LL*v*base+words[i][j]-'a')%mod;
            }
            invhash[i]=v;
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x=len[i],y=len[j];
                int h1=(1LL*hash[i]*fac[y]+hash[j])%mod;
                int h2=(1LL*invhash[j]*fac[x]+invhash[i])%mod;
                if(h1==h2) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
