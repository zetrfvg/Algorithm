/*
模拟方块的掉落的过程：
一个长为x的方块掉落在区间[l,r]中，我们要在区间[l,r]中找到最高的一个点记为h，然后我们需要将区间[l,r]的高度全部推平为x+h
涉及区间最值查询和区间推平，很自然的使用线段树来实现
*/
class Solution {
public:
    static const int INF=1e8+10;
    struct node{
        int l,r;
        int mx,add;
        node *ls,*rs;
        node(){};
        node(int _l,int _r){
            l=_l,r=_r,mx=0,add=0;
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
          left->mx=left->add=rt->add;
          right->mx=right->add=rt->add;
          rt->add=0;
        }
    }

    void modify(node* rt,int l,int r,int k){
        if(l<=rt->l&&rt->r<=r){
            rt->mx=rt->add=k;
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

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        root=new node(1,INF);
        int n=positions.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int h=query(root,positions[i][0],positions[i][0]+positions[i][1]-1);
            modify(root,positions[i][0],positions[i][0]+positions[i][1]-1,positions[i][1]+h);
            ans[i]=root->mx;
        }
        return ans;
    }
};
