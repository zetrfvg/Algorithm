struct ODT{
	struct node{
		int l,r,v;
		node(int l,int r,int v):l(l),r(r),v(r) {}
		bool operator< (const node& b) const{
			return l<b.l;
		}
	};
	set<node> tr;
	
	set<node>::iterator split(int p){//[l,r]->[l,p-1]+[p,r]
		auto it=tr.lower_bound(node(p,0,0));
		if(it!=tr.end()&&it->l==p) return it;
		it--;
		int l=it->l,r=it->r,v=it->v;
		tr.erase(it);
		tr.insert(node(l,p-1,v));
		return tr.insert(node(p,r,v)).first;
	}
	
	void assign(int l,int r,int v){
		auto right=split(r+1);
		auto left=split(l);
		tr.erase(left,right);
		tr.insert(node(l,r,v));
	}
	
	void insert(int l,int r,int v){
		tr.insert(node(l,r,v));	
	}
};
