/*
变形：nums1[i]-nums[i]-diff<=nums1[j]-nums2[j]
枚举j，在树状数组上查询小于等于nums1[j]-nums2[j]的个数，累加答案；在将nums1[j]-nums2[j]-diff加入树状数组
与求逆序对类似
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
    const int S=3e4+10;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        Fenwick<int> fen(S*2);
        long long ans=0;
        for(int i=0;i<nums1.size();i++){
            int v=nums1[i]-nums2[i]+S;
            ans+=1LL*fen.query(v);
            fen.add(v-diff,1);
        }
        return ans;
    }
};
