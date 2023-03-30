/*
指针实现
*/
class Trie {
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
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* cur=root;
        for(auto c:word){
            if(!cur->ch[c-'a']) cur->ch[c-'a']=new node();
            cur=cur->ch[c-'a'];
        }
        cur->tail=1;
    }
    
    bool search(string word) {
        node* cur=root;
        for(auto c:word){
            if(!cur->ch[c-'a']) return false;
            cur=cur->ch[c-'a'];
        }
        return cur->tail;
    }
    
    bool startsWith(string prefix) {
        node* cur=root;
        for(auto c:prefix){
            if(!cur->ch[c-'a']) return false;
            cur=cur->ch[c-'a'];
        }
        return true;
    }
};

/*
数组实现
*/
class Trie {
public:
    int ch[40010][26],tail[40010],idx;
    Trie() {
        memset(ch,0,sizeof ch);
        memset(tail,0,sizeof tail);
        idx=0;
    }
    
    void insert(string word) {
        int p=0;
        for(auto c:word){
            int j=c-'a';
            if(!ch[p][j]) ch[p][j]=++idx;
            p=ch[p][j];
        }
        tail[p]=1;
    }
    
    bool search(string word) {
        int p=0;
        for(auto c:word){
            int j=c-'a';
            if(!ch[p][j]) return false;
            p=ch[p][j];
        }
        return tail[p];
    }
    
    bool startsWith(string prefix) {
        int p=0;
        for(auto c:prefix){
            int j=c-'a';
            if(!ch[p][j]) return false;
            p=ch[p][j];
        }
        return true;
    }
};
