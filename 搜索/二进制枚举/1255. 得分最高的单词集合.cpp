/*
二进制枚举所有的子集
*/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        int ans=0;
        vector<vector<int>> cnt(n,vector<int>(26));
        vector<int> letter(26);
        for(int i=0;i<n;i++){
            for(auto &ch:words[i]){
                cnt[i][ch-'a']++;
            }
        }
        for(auto c:letters) letter[c-'a']++;
        for(int i=1;i<(1<<n);i++){
            int res=0,ok=1;
            vector<int> s(26);
            for(int j=0;j<n;j++){
                if(ok&&i&(1<<j)){
                    for(int k=0;k<26;k++){
                        s[k]+=cnt[j][k];
                        res+=cnt[j][k]*score[k];
                        if(s[k]>letter[k]){
                            ok=0;
                            break;
                        }
                    }
                }
            }
            if(ok) ans=max(ans,res);
        }
        return ans;
    }
};
