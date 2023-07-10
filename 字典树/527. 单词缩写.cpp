/*
按(首字母+串长度+尾字符)的形式进行分组
对于每一组中的串，我们要找到它们最短的独特的前缀
考虑对于每一组串，都建立一颗Trie，在这颗Trie上搜索串s
如果当前节点的计数大于1，则说明对于到这个节点为止的前缀，至少存在一个别的串也有这样的前缀，因此继续乡下搜索，直到找到计数等于1的节点，此时到该节点的前缀是独一无二的
*/
class Solution {
public:
    struct node{
        vector<node*> ch;
        int cnt;
        node(){
            cnt=0;
            ch=vector<node*>(26,NULL);
        }
    };
    node* root;
    void insert(string& s){
        node* cur=root;
        for(auto &c:s){
            if(!cur->ch[c-'a']) cur->ch[c-'a']=new node;
            cur=cur->ch[c-'a'];
            cur->cnt++;
        }
    }
    int query(string &s){
        node* cur=root;
        int res=1;
        for(auto &c:s){
            if(cur->ch[c-'a']->cnt>1){
                res++;
                cur=cur->ch[c-'a'];
            }else{
                break;
            }
        }
        return res;
    }
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n=words.size();
        vector<string> ans(n);
        unordered_map<string,vector<int>> p;
        for(int i=0;i<n;i++){
            string c=words[i][0]+to_string(words[i].size())+words[i].back();
            p[c].push_back(i);
        }
        for(auto &[_,v]:p){
            root=new node;
            for(auto &i:v) insert(words[i]);
            for(auto &i:v){
                int len=query(words[i]);
                if(words[i].size()-len>2){
                    ans[i]=words[i].substr(0,len)+to_string(words[i].size()-len-1)+words[i].back();
                }else{
                    ans[i]=words[i];
                }
            }
        }
        return ans;
    }
};
