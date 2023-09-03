/*
观察到，图上任何一个点经过若干次移动都会进入到环中
对于每个点，预处理出它的所有的2的幂次方的祖先，以及到达各个祖先的分数和
我们对于每个点，用倍增的方法来跳到它的第k个祖先，同时一边累加分数即可
*/
class Solution {
public:
    using ll=long long;
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int P=log2(k)+1;
        int n=receiver.size();
        vector<vector<int>> fa(n,vector<int>(P));
        vector<vector<ll>> w(n,vector<ll>(P));
        for(int i=0;i<n;i++){
            fa[i][0]=w[i][0]=receiver[i];
        }
        for(int j=1;j<P;j++){
            for(int i=0;i<n;i++){
                fa[i][j]=fa[fa[i][j-1]][j-1];
                w[i][j]=w[i][j-1]+w[fa[i][j-1]][j-1];
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ll cur=i;
            int x=i;
            for(int j=P-1;~j;j--){
                if(k&(1LL<<j)){
                    cur+=w[x][j];
                    x=fa[x][j];
                } 
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};
