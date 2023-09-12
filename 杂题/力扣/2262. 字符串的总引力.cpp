/*
枚举子串的右端点i，记pre为以s[i-1]为右端点所有子串的引力和，字符s[i]上次出现的位置为j，则以i为右端点所有字串增加的引力和为i-j
累加答案即可
*/
class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        int n=s.size();
        vector<int> f(26,n);
        for(int i=n-1;~i;i--){
            f[s[i]-'a']=i;
            for(int j=0;j<26;j++){
                ans+=n-f[j];
            }
        }
        return ans;
    }
};
