/*
通过前缀和可以在O(Σ)的复杂度内计算出区间[l,r]中字符的差异值，Σ为字符集大小
我们统计区间中有多少字符是奇数，是奇数说明该字符多出一个无法匹配，需要更改，设区间[l,r]中共有cnt个字符是奇数
当cnt/2>k时这时无解
*/
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<vector<int>> f(n+1,vector<int>(26));
        for(int i=0;i<n;i++){
            f[i+1][s[i]-'a']++;
            for(int j=0;j<26;j++){
                f[i+1][j]+=f[i][j];
            }
        }
        vector<bool> ans;
        for(auto &q:queries){
            q[1]++;
            int cnt=0;
            for(int i=0;i<26;i++){
                if((f[q[1]][i]-f[q[0]][i])&1) cnt++;
            }
            if(cnt/2>q[2]) ans.push_back(0);
            else ans.push_back(1);
        }
        return ans;
    }
};
