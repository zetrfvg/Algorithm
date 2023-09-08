/*
利用SAM找到cnt>1且len最大的状态节点x
反向建图，x向根结点跳如果x有多个父节点，则任选一个len[fa]+1=len[x]跳即可
*/
class Solution {
public:
    static const int N=6e4+10;
    vector<int> e[N];
    long long cnt[N];
    int tot=1,np=1;
    int fa[N],ch[N][26],len[N];

    void extend(int c){//建立SAM
        int p=np;
        np=++tot,len[np]=len[p]+1,cnt[np]=1;
        for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
        if(!p) fa[np]=1;
        else{
            int q=ch[p][c];
            if(len[q]==len[p]+1) fa[np]=q;
            else{
                int nq=++tot;
                len[nq]=len[p]+1;
                fa[nq]=fa[q],fa[q]=nq,fa[np]=nq;
                for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
                memcpy(ch[nq],ch[q],sizeof ch[q]);
            }
        }
    }

    void dfs(int x){//求节点中子串出现的个数
        for(auto y:e[x]){
            dfs(y);
            cnt[x]+=cnt[y];
        }
    }

    string longestDupSubstring(string s) {
        for(auto c:s) extend(c-'a');
        int n=s.size();
        for(int i=1;i<=tot;i++) e[fa[i]].push_back(i);
        dfs(1);
        int pos=0;
        vector<vector<pair<int,int>>> ed(tot+1);
        for(int i=1;i<=tot;i++){
            for(int j=0;j<26;j++){
                if(ch[i][j]){
                    ed[ch[i][j]].push_back({i,j});
                }
                if(cnt[i]>1&&len[i]>len[pos]) pos=i;
            }
        }
        string ans;
        while(pos>1){
            for(auto &[pre,j]:ed[pos]){
                if(len[pre]+1==len[pos]){
                    ans+='a'+j;
                    pos=pre;
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
