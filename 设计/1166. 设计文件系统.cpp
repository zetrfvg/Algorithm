/*
字典树模拟设计
*/
class FileSystem {
public:
    struct node{
        unordered_map<string,node*> ch;
        int v;
    };
    node* root=new node;
    FileSystem() {

    }
    
    bool createPath(string path, int value) {
        vector<string> e;
        string s;
        int n=path.size();
        for(int i=1;i<n;i++){
            if(path[i]=='/'){
                e.push_back(s);
                s.clear();
            }else s+=path[i];
        }
        auto cur=root;
        for(auto &t:e){
            if(!cur->ch[t]) return false;
            cur=cur->ch[t];
        }
        if(cur->ch[s]) return false;
        cur->ch[s]=new node;
        cur->ch[s]->v=value;
        return true;
    }
    
    int get(string path) {
        path+='/';
        vector<string> e;
        string s;
        int n=path.size();
        for(int i=1;i<n;i++){
            if(path[i]=='/'){
                e.push_back(s);
                s.clear();
            }else s+=path[i];
        }
        auto cur=root;
        for(auto &t:e){
            if(!cur->ch[t]) return -1;
            cur=cur->ch[t];
        }
        return cur->v;
    }
};
