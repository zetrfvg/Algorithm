/*
转换题意：对于[0,n-1]中的任意一个元素，它都有两种属性：在nums1中的位置p1，在nums2中的位置p2，元素值的大小和题意求解的问题无关
考虑n个元素，第i种元素，属性有p1[i],p2[i]
对于三元组x，y，z，我们枚举y，两种属性均小于它的元素有c1个，两种属性均大于它的元素有c2个
依乘法原理，则当前y为三元组的个数有c1*c2个
对所有元素按p1排序，枚举过的元素p2和未枚举过的元素的p2用树状数组维护即可

解决二维度偏序就是，排序后枚举一维，数据结构维护另一维
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
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<array<int,2>> g(n);
        Fenwick<int> pre(n),suf(n);
        for(int i=0;i<n;i++){
            g[nums1[i]][0]=i+1;
            g[nums2[i]][1]=i+1;
            suf.add(i+1,1);
        }
        sort(g.begin(),g.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            int x=g[i][0],y=g[i][1];
            suf.add(y,-1);
            ans+=1LL*pre.query(y)*(suf.query(n)-suf.query(y));
            pre.add(y,1);
        }
        return ans;
    }
};
