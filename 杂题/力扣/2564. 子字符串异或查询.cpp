/*
位数不超过30，预处理出串中所有合法的数，用哈希存下来，即可做到O(logn)回答询问
*/
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries){
        int n=s.size();
        map<int,pair<int,int>> p;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(!p.count(0)) p[0]={i,i};
                continue;
            }
            int num=0;
            for(int d=0,j=i;j<n&&d<30;d++,j++){
                num<<=1;
                if(s[j]=='1') num|=1;
                if(!p.count(num)) p[num]={i,i+d};
            }
        }
        vector<vector<int>> ans;
        for(auto q:queries){
            int x=q[0]^q[1];
            if(!p.count(x)) ans.push_back({-1,-1});
            else ans.push_back({p[x].first,p[x].second});
        }
        return ans;
    }
};
