template<typename T>
struct Fenwick{
	int n;
	vector<T> tr;
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
    int reversePairs(vector<int>& nums) {
        vector<int> f=nums;
        sort(f.begin(),f.end());
        f.resize(unique(f.begin(),f.end())-f.begin());
        auto get=[&](int x){
            return lower_bound(f.begin(),f.end(),x)-f.begin()+1;
        };
        int m=f.size();
        Fenwick<int> fen(m);
        int ans=0;
        for(auto c:nums){
            ans+=fen.query(m)-fen.query(get(c));
            fen.add(get(c),1);
        }
        return ans;
    }
};
