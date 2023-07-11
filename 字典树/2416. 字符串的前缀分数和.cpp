/*
建立字典树，一个串的前缀分数和等于它在字典树上中经过的路径上的所有节点权值和
*/
class Solution {
public:
    struct node{
        unordered_map<int,node*> ch;
        int cnt=0;
    };
    node* root=new node;
    void insert(string &s){
        node* cur=root;
        for(auto &c:s){
            if(!cur->ch[c-'a']) cur->ch[c-'a']=new node();
            cur=cur->ch[c-'a'];
            cur->cnt++;
        }
    }
    int query(string &s){
        int res=0;
        node* cur=root;
        for(auto &c:s){
            cur=cur->ch[c-'a'];
            res+=cur->cnt;
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        vector<int> ans(n);
        for(auto &s:words) insert(s);
        for(int i=0;i<n;i++){
            ans[i]=query(words[i]);
        }
        return ans;
    }
};
