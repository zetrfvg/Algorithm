/*
记录前缀，遇到1则+1，遇到0则-1
枚举到nums[i]，此时前缀为pre，我们要在之前的前缀中找到小于pre的数的个数
这些数满足它们对应的位置到nums[i]这个序列上的1的个数多余0
前缀使用树状数组来维护，因为存在前缀存在负数，因此加入一个偏移量S
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
    static const int N=2e5+50,S=1e5+10,mod=1e9+7;
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int n=nums.size();
        Fenwick<int> fen(N);
        int pre=0,ans=0;
        fen.add(S,1);
        for(int i=0;i<n;i++){
            pre+=nums[i]?1:-1;
            if(pre>0) ans=(1LL*ans+fen.query(S+pre-1))%mod;
            else ans=(1LL*ans+fen.query(S+pre-1))%mod;
            fen.add(S+pre,1);
        }
        return ans;
    }
};
