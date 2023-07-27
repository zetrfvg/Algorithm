/*
移项后，nums1[i]-nums2[i]>-nums1[j]+nums2[j]，记nums1[k]-nums2[k]=diff[k]
题意变为对于i，找到所有的j，使diff[i]>-diff[j]
经典的树状数组求解即可
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
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        const int delta=1e5+10;
        Fenwick<int> fen(delta*2+100);
        int n=nums1.size();
        long long ans=0;
        for(int i=n-1;~i;i--){
            ans+=1LL*fen.query(nums1[i]-nums2[i]+delta-1);
            fen.add(nums2[i]-nums1[i]+delta,1);
        }
        return ans;
    }
};
