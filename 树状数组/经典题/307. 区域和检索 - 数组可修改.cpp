/*
树状数组————单点修改、区间求和
*/
template<typename T>
struct Fenwick{
	int n;
	vector<T> tr;
    Fenwick(){}
	Fenwick(int _n):tr(_n+1),n(_n){
		for(int i=0;i<=n;i++) tr[i]=0;
	}
	T lowbit(T x){
		return x&-x;
	}
	void add(int u,T x){
		for(int i=u;i<=n;i+=lowbit(i)) tr[i]+=x;
	}
	T query(int u){
		T res=0;
		for(int i=u;i;i-=lowbit(i)) res+=tr[i];
		return res;
	}
};
class NumArray {
public:
    Fenwick<int> fen;
    vector<int> g;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        fen=Fenwick<int>(n);
        g.resize(n);
        for(int i=0;i<n;i++){
            fen.add(i+1,nums[i]);
            g[i]=nums[i];
        }
    }
    
    void update(int index, int val) {
        fen.add(index+1,val-g[index]);
        g[index]=val;
    }
    
    int sumRange(int left, int right) {
        return fen.query(right+1)-fen.query(left);
    }
};
