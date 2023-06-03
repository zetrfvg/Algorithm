/*
初始化向树中加入一个区间为[1,1e9]的区间，赋值0
增加区间：推平这段区间[l,r]赋值为1
查询区间：依次查询这个区间内的所有区间权值是否都是1
删除区间：推平这段区间[l,r]赋值为0
*/
struct ODT{
	struct node{
		int l,r,v;
		node(int l,int r,int v):l(l),r(r),v(v) {}
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
class RangeModule {
public:
	ODT odt;
	RangeModule() {
		odt.insert(1,1e9,0);
	}
	
	void addRange(int left, int right) {
		odt.assign(left,right-1,1);
	}
	
	bool queryRange(int left, int right) {
		auto r=odt.split(right);
		auto l=odt.split(left);
		for(auto it=l;it!=r;it++){
			if(it->v==0) return false;
		}
		return true;
	}
	
	void removeRange(int left, int right) {
		odt.assign(left,right-1,0);
	}
};
