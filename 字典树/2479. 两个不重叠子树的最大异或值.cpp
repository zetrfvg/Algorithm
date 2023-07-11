/*
先统计所有节点的子树和
DFS这棵树，对于枚举到的节点：
先在字典树中查找最大异或和，然后DFS这个子树，最后把这个子树的和插入字典树中
*/
using ll=long long;
class Solution {
public:
    struct node{
        vector<node*> ch;
        node(){
            ch=vector<node*>(2,NULL);
        }
    };
    node* root=new node;
    void insert(ll x){
        node* cur=root;
        for(int i=45;~i;i--){
            int j=(x>>i)&1;
            if(!cur->ch[j]) cur->ch[j]=new node;
            cur=cur->ch[j];
        }
    }
    ll query(ll x){
        ll res=0;
        node* cur=root;
        for(int i=45;~i;i--){
            int j=(x>>i)&1;
            if(cur->ch[!j]){
                cur=cur->ch[!j];
                res|=(1LL<<i);
            }
            else if(cur->ch[j]) cur=cur->ch[j];
            else return 0;
        }
        return res;
    }
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> e(n);
        for(auto &p:edges){
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        vector<ll> w(n);
        function<void(int,int)> dfs1=[&](int x,int fa){
            w[x]=values[x];
            for(auto &y:e[x]){
                if(y==fa) continue;
                dfs1(y,x);
                w[x]+=w[y];
            }
        };
        dfs1(0,-1);
        ll ans=0;
        function<void(int,int)> dfs2=[&](int x,int fa){
            ans=max(ans,query(w[x]));
            for(auto &y:e[x]){
                if(y==fa) continue;
                dfs2(y,x);
            }
            insert(w[x]);
        };
        dfs2(0,-1);
        return ans;
    }
};
