/*
逆序对的变形
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
    int reversePairs(vector<int>& nums) {
        vector<long long> b(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++) b.push_back(b[i]*2);
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
		    Fenwick<int> fen(n*2);
        long long ans=0;
        auto get=[&](long long x){
            return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
        };
        for(int i=0;i<n;i++){
            ans+=fen.query(2*n)-fen.query(get(2LL*nums[i]));
            fen.add(get(nums[i]),1);
        }
        return ans;
    }
};
