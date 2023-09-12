/*
简单哈希构造
*/
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        const int mod=1e9+7,P=131;
        vector<vector<string>> ans;
        map<pair<int,int>,vector<string>> p;
        for(auto s:strings){
            int sum=0;
            for(int i=1;i<s.size();i++){
                sum=(1LL*sum*P+1LL*(s[i]-s[i-1]+26)%26)%mod;
            }
            p[{s.size(),sum}].push_back(s);
        }
        for(auto &[a,b]:p) ans.push_back(b);
        return ans;
    }
};
