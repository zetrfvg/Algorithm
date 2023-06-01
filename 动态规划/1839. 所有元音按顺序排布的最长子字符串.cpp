/*
dp递推，细节多
*/
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.size();
        int ans=0;
        for(auto &c:word){
            if(c=='e') c='b';
            else if(c=='i') c='c';
            else if(c=='o') c='d';
            else if(c=='u') c='e';
        }
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(word[i]=='a') dp[i]=1;
            if(i&&(word[i]==word[i-1]||word[i]==word[i-1]+1)&&dp[i-1]) dp[i]=dp[i-1]+1;
            if(word[i]=='e'&&dp[i]>=5) ans=max(ans,dp[i]);
        }
        return ans;
    }
};
