/*
按字典序顺序建图，跑一遍拓扑排序即可
特殊情况特判
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<int>> e(26);
        vector<int> deg(26),exist(26);
        int cnt=0;
        for(auto &s:words){
            for(auto &c:s){
                exist[c-'a']=1;
            }
        }
        int n=words.size();
        for(int i=1;i<n;i++){
            string &s=words[i-1],&t=words[i];
            int n=s.size(),m=t.size();
            int l=0,r=0;
            if(n>m&&s.substr(0,m)==t) return "";
            while(l<n&&r<m){
                if(s[l]!=t[r]){
                    e[s[l]-'a'].push_back(t[r]-'a');
                    deg[t[r]-'a']++;
                    break;
                }
                l++,r++;
            }
        }
        queue<int> q;
        string ans;
        for(int i=0;i<26;i++){
            cnt+=exist[i];
            if(exist[i]&&!deg[i]){
                q.push(i);
                ans+='a'+i;
            }
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto y:e[x]){
                if(!--deg[y]){
                    q.push(y);
                    ans+='a'+y;
                }
            }
        }
        return ans.size()==cnt?ans:"";
    }
};
