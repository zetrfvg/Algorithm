/*
因为要找回文，我们枚举任意一个串，然后去寻找它的另一半即可
因此考虑将所有串反转，然后构成一颗字典树
对于串s去找到能够组成回文串的串t
s+t回文，分两种情况：
s.size()>=t.size()与s.size()<t.size()
对于串s，我们直接往树中查找：
1、如果s.size()>=t.size()，则会直接找到t串的尾部，此时加入答案即可
2、如果s.size()<t.size()，则说明我们找到对应t之前就会走完s串，因此我们要在字典树的节点中维护一些额外的信息，我们用一个suf数组来存储当前节点的回文后缀对应的下标。
假设串t在树中已经插入了前i个字符，然后判断一下后j个字符是否回文，如果回文，则在当前节点的suf中加入t串对应的下标。
这样我们不必枚举到t尾部，就能够找到这个t串
*/
class Solution {
public:
    struct node{
        vector<node*> ch;
        vector<int> suf;
        int tail=-1;
        node(){
            ch=vector<node*>(26,NULL);
            suf=vector<int>();
            tail=-1;
        }
    };
    node *root;
    vector<vector<int>> ans;
    void insert(string &s,int idx){
        node *cur=root;
        int m=s.size()-1;
        if(check(s,0,m)){
            cur->suf.push_back(idx);
        }
        for(int i=0;i<=m;i++){
            int j=s[i]-'a';
            if(!cur->ch[j]) cur->ch[j]=new node();
            cur=cur->ch[j];
            if(check(s,i+1,m)) cur->suf.push_back(idx);
        }
        cur->tail=idx;
    }
    void query(string &s,int idx){
        int m=s.size()-1;
        node *cur=root;
        for(int i=0;i<=m;i++){
            if(check(s,i,m)){
                if(cur->tail!=idx&&cur->tail!=-1) ans.push_back({idx,cur->tail});
            }
            int j=s[i]-'a';
            if(!cur->ch[j]) return;
            cur=cur->ch[j];
        }
        for(auto k:cur->suf){
            if(k!=idx) ans.push_back({idx,k});
        }
    }
    bool check(string &s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root=new node();
        int n=words.size();
        for(int i=0;i<n;i++){
            string s=words[i];
            reverse(s.begin(),s.end());
            insert(s,i);
        }
        for(int i=0;i<n;i++){
            query(words[i],i);
        }
        return ans;
    }
};
