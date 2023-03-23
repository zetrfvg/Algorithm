/*
LIS运用题
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int> dp(n);
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<n;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
/*
基于LIS贪心+二分的做法
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int> g;
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            int l=pairs[i][0],r=pairs[i][1];
            if(!g.size()||l>g.back()){
                g.push_back(r);
            }else{
                int j=lower_bound(g.begin(),g.end(),l)-g.begin();
                g[j]=min(g[j],r);
            }
        }
        return g.size();
    }
};
