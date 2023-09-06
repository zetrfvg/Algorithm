/*
预处理前缀和，然后暴力枚举每个子串是否合法
*/
class Solution {
public:
    int equalDigitFrequency(string s) {
        int n=s.size();
        vector<vector<int>> f(n+1,vector<int>(10));
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                f[i+1][j]+=f[i][j];
            }
            f[i+1][s[i]-'0']++;
        }
        auto check=[&](int i,int j){
            int cnt=-1;
            for(int k=0;k<10;k++){
                int t=f[i][k]-f[j][k];
                if(t){
                    if(cnt!=-1&&cnt!=t) return false;
                    else if(cnt==-1) cnt=t;
                }
            }
            return true;
        };
        unordered_set<string> ans;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(check(i,j)){
                    ans.insert(s.substr(j,i-j));
                }
            }
        }
        return ans.size();
    }
};
