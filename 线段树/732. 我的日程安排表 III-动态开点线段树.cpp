/*
与731题一样，使用动态开点线段树解决即可
*/
class MyCalendarThree {
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

    MyCalendarThree() {
        root=new node(0,INF);
    }
    
    int book(int startTime, int endTime) {
        modify(root,startTime,endTime-1,1);
        return root->mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
