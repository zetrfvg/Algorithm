/*
哈希表构造双射
*/
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=words[0].size();
        vector<string> ans;
        auto check=[&](string s){
            vector<int> to(26,-1),from(26,-1);
            for(int i=0;i<n;i++){
                if(to[s[i]-'a']==-1){
                    if(from[pattern[i]-'a']!=-1) return false;
                    to[s[i]-'a']=pattern[i]-'a';
                    from[pattern[i]-'a']=s[i]-'a';
                }else if(to[s[i]-'a']!=pattern[i]-'a'||from[pattern[i]-'a']!=s[i]-'a') return false;
            }
            return true;
        };
        for(int i=0;i<words.size();i++){
            if(check(words[i])) ans.push_back(words[i]);
        }
        return ans;
    }
};
