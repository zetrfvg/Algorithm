/*
每加入一个区间，我们需要把这个区间中的所有位置赋值为1，即区间推平操作
*/
class CountIntervals {
public:
    static const int INF=1e9+10;
    struct node{
        int l,r;
        int sum;
        node *ls,*rs;
        node(){};
        node(int _l,int _r){
            l=_l,r=_r,sum=0;
            ls=rs=NULL;
        }
    };

    node* root;

    node* get_left(node* rt){
        if(!rt->ls){
            rt->ls=new node(rt->l,(rt->l+rt->r)/2);
        }
        return rt->ls;
    }

    node* get_right(node* rt){
        if(!rt->rs){
            rt->rs=new node((rt->l+rt->r)/2+1,rt->r);
        }
        return rt->rs;
    }

    void pushup(node* rt){
        rt->sum=get_left(rt)->sum+get_right(rt)->sum;
    }

    void pushdown(node* rt){
        auto left=get_left(rt);
        auto right=get_right(rt);
        if(rt->sum==rt->r-rt->l+1){
            left->sum=left->r-left->l+1;
            right->sum=right->r-right->l+1;
        }
    }

    void modify(node* rt,int l,int r){
        if(l<=rt->l&&rt->r<=r){
            rt->sum=(rt->r-rt->l+1);
            return;
        }
        int m=(rt->l+rt->r)>>1;
        pushdown(rt);
        if(l<=m) modify(rt->ls,l,r);
        if(r>m) modify(rt->rs,l,r);
        pushup(rt);
    }

    int query(node* rt,int l,int r){
        if(l<=rt->l&&rt->r<=r){
            return rt->sum;
        }
        int m=(rt->l+rt->r)>>1;
        pushdown(rt);
        int res=0;
        if(l<=m) res+=query(rt->ls,l,r);
        if(r>m) res+=query(rt->rs,l,r);
        pushup(rt);
        return res;
    }

    CountIntervals() {
        root=new node(1,INF);
    }
    
    void add(int left, int right) {
        modify(root,left,right);
    }
    
    int count() {
        return root->sum;
    }
};
