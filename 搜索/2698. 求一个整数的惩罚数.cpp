/*
n范围不大，暴搜即可
*/
class Solution {
public:
    int punishmentNumber(int n) {
        int ans=0;
        function<bool(int,string,int,int,int)> dfs=[&](int i,string s,int sum,int cur,int des){
            if(sum+cur>des) return false;
            if(i==s.size()) return sum+cur==des;
            bool res=false;
            res|=dfs(i+1,s,sum,cur*10+s[i]-'0',des);
            res|=dfs(i+1,s,sum+cur,s[i]-'0',des);
            return res;
        };
        for(int i=1;i<=n;i++){
            int x=i*i;
            if(dfs(0,to_string(x),0,0,i)) ans+=x;
        }
        return ans;
    }
};
