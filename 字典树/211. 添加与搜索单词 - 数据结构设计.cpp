/*
用字典树维护插入的单词
对于查询的单词，如果是字母，则直接向下查询
如果是'.'，则需要对当前节点的所有非空节点进行暴搜
*/
class WordDictionary {
public:
    struct node{
        vector<node*> ch;
        bool tail=0;
        node(){
            ch=vector<node*>(26,NULL);
            tail=0;
        }
    };
    node* root;
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node* cur=root;
        for(auto c:word){
            if(!cur->ch[c-'a']) cur->ch[c-'a']=new node();
            cur=cur->ch[c-'a'];
        }
        cur->tail=1;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }

    bool dfs(string s,int u,node *cur){
        if(u==s.size()){
            return cur->tail;
        }
        if(s[u]=='.'){
            for(int j=0;j<26;j++){
                if(cur->ch[j]){
                    if(dfs(s,u+1,cur->ch[j])) return true;
                }
            }
            return false;
        }else if(cur->ch[s[u]-'a']){
            return dfs(s,u+1,cur->ch[s[u]-'a']);
        }else{
            return false;
        }
    }
};
