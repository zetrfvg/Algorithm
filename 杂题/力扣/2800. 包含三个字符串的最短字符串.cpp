/*
枚举所有的6中拼接情况，取最短的串中字典序最小的即可
拼接的过程暴力模拟
*/
class Solution {
public:
    string minimumString(string a, string b, string c) {
        string ans;
        function<string(string,string,string)> f=[&](string a, string b, string c){
            string res=a;
            if(res.find(b)==string::npos){
                bool ok=1;
                for(int i=0;i<res.size();i++){
                    if(res.size()-i>=b.size()) continue;
                    if(res.substr(i)==b.substr(0,res.size()-i)){
                        res+=b.substr(res.size()-i);
                        ok=0;
                        break;
                    }
                }
                if(ok) res+=b;
            }
            if(res.find(c)==string::npos){
                bool ok=1;
                for(int i=0;i<res.size();i++){
                    if(res.size()-i>=c.size()) continue;
                    if(res.substr(i)==c.substr(0,res.size()-i)){
                        res+=c.substr(res.size()-i);
                        ok=0;
                        break;
                    }
                }
                if(ok) res+=c;
            }
            return res;
        };
        vector<vector<string>> d{{a,b,c},{a,c,b},{b,a,c},{b,c,a},{c,a,b},{c,b,a}};
        for(auto r:d){
            auto t=f(r[0],r[1],r[2]);
            if(!ans.size()||ans.size()>t.size()) ans=t;
            else if(ans.size()==t.size()) ans=min(ans,t);
        }
        return ans;
    }
};
