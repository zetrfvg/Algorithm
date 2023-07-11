/*
在字典树中查询每个单词的所有前缀是否都存在即可
*/
class Solution {
public:
    struct node{
        unordered_map<char,node*> ch;
        int tail=0;
    };
    node* root=new node;
    void insert(string &s){
        auto cur=root;
        for(auto &c:s){
            if(!cur->ch[c]) cur->ch[c]=new node;
            cur=cur->ch[c];
        }
        cur->tail=1;
    }
    bool query(string &s){
        auto cur=root;
        int res=0;
        for(auto &c:s){
            cur=cur->ch[c];
            if(!cur->tail) return false;
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end());
        for(auto &s:words) insert(s);
        string ans;
        for(auto &s:words){
            if(query(s)){
                if(s.size()>ans.size()) ans=s;
            }
        }
        return ans;
    }
};
