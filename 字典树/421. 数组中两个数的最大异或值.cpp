/*
01-Trie
*/
class Solution {
public:
    struct node{
        vector<node*> ch;
        node(){
            ch=vector<node*>(2,NULL);
        }
    };
    node *root;
    void insert(int u){
        node *cur=root;
        for(int i=30;~i;i--){
            int j=(u>>i)&1;
            if(!cur->ch[j]) cur->ch[j]=new node();
            cur=cur->ch[j];
        }
    }
    int query(int u){
        node *cur=root;
        int res=0;
        for(int i=30;~i;i--){
            int j=(u>>i)&1;
            if(cur->ch[!j]){
                res|=(1<<i);
                cur=cur->ch[!j];
            }else{
                cur=cur->ch[j];
            }
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        root=new node();
        int ans=0;
        for(auto &x:nums){
            insert(x);
            ans=max(ans,query(x));
        }
        return ans; 
    }
};
