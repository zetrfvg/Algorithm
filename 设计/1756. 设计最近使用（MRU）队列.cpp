/*
暴力模拟
*/
class MRUQueue {
public:
    vector<int> p;
    MRUQueue(int n){
        p.resize(n);
        iota(p.begin(),p.end(),1);
    }
    
    int fetch(int k){
        int res=p[k-1];
        for(int i=k;i<p.size();i++) p[i-1]=p[i];
        p.back()=res;
        return res;
    }
};
