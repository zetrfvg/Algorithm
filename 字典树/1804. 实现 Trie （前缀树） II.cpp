/*
简单Trie上计数
*/
class Trie {
public:
    struct node{
        unordered_map<char,node*> ch;
        int cnt=0;
        int tail=0;
    };
    node* root=new node;
    Trie() {

    }
    
    void insert(string word) {
        auto cur=root;
        for(auto &c:word){
            if(!cur->ch[c]) cur->ch[c]=new node;
            cur=cur->ch[c];
            cur->cnt++;
        }
        cur->tail++;
    }
    
    int countWordsEqualTo(string word) {
        auto cur=root;
        for(auto &c:word){
            if(!cur->ch[c]) return 0;
            cur=cur->ch[c];
        }
        return cur->tail;
    }
    
    int countWordsStartingWith(string prefix) {
        auto cur=root;
        for(auto &c:prefix){
            if(!cur->ch[c]) return 0;
            cur=cur->ch[c];
        }
        return cur->cnt;
    }
    
    void erase(string word) {
        auto cur=root;
        for(auto &c:word){
            cur=cur->ch[c];
            cur->cnt--;
        }
        cur->tail--;
    }
};
