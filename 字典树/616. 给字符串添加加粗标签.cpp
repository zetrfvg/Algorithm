/*
字典树存储所有的words串
枚举s的所有后缀，找到所有需要标签的区间并进行合并即可
*/
class Solution {
public:
    static const int N=1e5+10;
    int ch[N][128],cnt[N];
    int idx=0;
    void insert(string &s){
        int p=0;
        for(auto &c:s){
            if(!ch[p][c]) ch[p][c]=++idx;
            p=ch[p][c];
        }
        cnt[p]=1;
    }
    int query(string s){
        int res=0,p=0,cur=0;
        for(auto &c:s){
            if(!ch[p][c]) return res;
            cur++;
            p=ch[p][c];
            if(cnt[p]) res=cur;
        }
        return res;
    }
    string addBoldTag(string s, vector<string>& words) {
        string ans;
        int n=s.size();
        for(auto &s:words) insert(s);
        vector<pair<int,int>> e;
        for(int i=0;i<n;i++){
            int len=query(s.substr(i));
            if(len){
                if(e.size()&&i<=e.back().second+1){
                    e.back().second=max(e.back().second,i+len-1);
                }else{
                    e.push_back({i,i+len-1});
                }
            }
        }
        //for(auto [a,b]:e) cout<<a<<" "<<b<<'\n';
        for(int i=0,j=0;i<n;i++){
            if(j<e.size()&&i==e[j].first){
                ans+="<b>";
            }
            ans+=s[i];
            if(j<e.size()&&i==e[j].second){
                ans+="</b>";
                j++;
            }
        }
        return ans;
    }
};
