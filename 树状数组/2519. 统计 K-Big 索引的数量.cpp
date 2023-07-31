/*
树状数组简单应用
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
    int kBigIndices(vector<int>& nums, int k) {
        int n=nums.size();
        Fenwick<int> pre(n),suf(n);
        for(auto c:nums) suf.add(c,1);
        int ans=0;
        for(auto c:nums){
            if(pre.query(c-1)>=k&&suf.query(c-1)>=k) ans++;
            suf.add(c,-1);
            pre.add(c,1);
        }
        return ans;
    }
};
