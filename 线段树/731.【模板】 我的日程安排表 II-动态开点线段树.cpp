class MyCalendarTwo {
public:
    static const int INF=1e9+10;
    struct node{
        int l,r;
        int mx,add;
        node *ls,*rs;
        node(){};
        node(int _l,int _r){
            l=_l,r=_r,mx=add=0;
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
        rt->mx=max(get_left(rt)->mx,get_right(rt)->mx);
    }

    void pushdown(node* rt){
        auto left=get_left(rt);
        auto right=get_right(rt);
        if(rt->add){
            left->mx+=rt->add;
            left->add+=rt->add;
            right->mx+=rt->add;
            right->add+=rt->add;
            rt->add=0;
        }
    }

    void modify(node* rt,int l,int r,int k){
        if(l<=rt->l&&rt->r<=r){
            rt->mx+=k;
            rt->add+=k;
            return;
        }
        int m=(rt->l+rt->r)>>1;
        pushdown(rt);
        if(l<=m) modify(rt->ls,l,r,k);
        if(r>m) modify(rt->rs,l,r,k);
        pushup(rt);
    }

    int query(node* rt,int l,int r){
        if(l<=rt->l&&rt->r<=r){
            return rt->mx;
        }
        int m=(rt->l+rt->r)>>1;
        pushdown(rt);
        int res=0;
        if(l<=m) res=max(res,query(rt->ls,l,r));
        if(r>m) res=max(res,query(rt->rs,l,r));
        pushup(rt);
        return res;
    }

    MyCalendarTwo() {
        root=new node(0,INF);
    }
    
    bool book(int start, int end) {
        if(query(root,start,end-1)<=1){
            modify(root,start,end-1,1);
            return true;
        }
        return false;
    }
};
