/*
二进制枚举分割点的所有情况
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        int m=n-1;
        vector<vector<string>> ans;
        auto check=[&](int st){
            vector<string> t;
            string u;
            for(int j=0;j<n;j++){
                u+=s[j];
                if(st&(1<<j)){
                    for(int l=0,r=u.size()-1;l<r;l++,r--){
                        if(u[l]!=u[r]) return vector<string>{};
                    }
                    t.push_back(u);
                    u.clear();
                }
            }
            return t;
        };
        for(int i=0;i<(1<<m);i++){
            auto t=check(i+(1<<m));
            if(t.size()) ans.push_back(t);
        }
        return ans;
    }
};
