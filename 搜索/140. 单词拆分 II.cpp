/*
回溯暴搜即可
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<string> ans;
        int n=s.size();
        function<void(int,string)> dfs=[&](int x,string t){
            if(x==n){
                t.pop_back();
                ans.push_back(t);
                return;
            }
            for(int i=x;i<n;i++){
                if(st.count(s.substr(x,i-x+1))){
                    dfs(i+1,t+s.substr(x,i-x+1)+" ");
                }
            }
        };
        dfs(0,"");
        return ans;
    }
};
