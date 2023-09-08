/*
利用性质：节点子串数量：len[x]-len[fa[x]]
*/
class Solution {
public:
    static const int N=1010;
    vector<int> e[N];
    int tot=1,np=1;
    int fa[N],ch[N][26],len[N];

    void extend(int c){
        int p=np;
        np=++tot,len[np]=len[p]+1;
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
    int countDistinct(string s) {
        for(auto c:s) extend(c-'a');
        int ans=0;
        for(int i=1;i<=tot;i++) ans+=len[i]-len[fa[i]];
        return ans;
    }
};
