/*
树状数组维护元素个数，模拟插入即可
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
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int mod=1e9+7;
        int n=instructions.size();
        Fenwick<int> fen(1e5);
        int ans=0;
        for(int i=0;i<n;i++){
            int l=fen.query(instructions[i]-1);
            int r=fen.query(1e5)-fen.query(instructions[i]);
            ans=(ans+min(l,r))%mod;
            fen.add(instructions[i],1);
        }
        return ans;
    }
};
