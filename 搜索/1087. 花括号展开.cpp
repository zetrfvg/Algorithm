 /*
 展开之后，暴力枚举所有串的组合形式即可
 */
class Solution {
public:
    vector<string> expand(string s) {
        vector<vector<char>> p;
        int n=s.size(),f=0;
        for(int i=0;i<n;i++){
            if(s[i]=='{'){
                f=1;
                p.push_back({});
            }
            if(s[i]=='}') f=0;
            if(s[i]>='a'&&s[i]<='z'){
                if(f) p.back().push_back(s[i]);
                else p.push_back({s[i]});
            }
        }
        for(auto &vec:p) sort(vec.begin(),vec.end());
        vector<string> ans;
        string t;
        function<void(int)> dfs=[&](int pos){
            if(pos==p.size()){
                ans.push_back(t);
                return;
            }
            for(auto ch:p[pos]){
                t+=ch;
                dfs(pos+1);
                t.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
