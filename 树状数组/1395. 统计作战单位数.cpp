/*
双树状数组应用，对于第i个单位，一个维护i之前的单位的rating，一个维护i之后的单位的rating
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
    const int N=1e5+10;
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        Fenwick<int> pre(N),suf(N);
        for(auto c:rating) suf.add(c,1);
        int ans=0;
        for(int i=0;i<n;i++){
            suf.add(rating[i],-1);
            ans+=(suf.query(N)-suf.query(rating[i]))*pre.query(rating[i]-1);//i<j<k
            ans+=(pre.query(N)-pre.query(rating[i]))*suf.query(rating[i]-1);//i>j>k
            pre.add(rating[i],1);
        }
        return ans;
    }
};
