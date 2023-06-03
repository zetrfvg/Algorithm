/*
树状数组来维护所有元素，因为存在负数，所有对于所有元素都加上一个偏移量delta，保证每个数都为正数
枚举nums[i]，执行树状数组的query(nums[i]+delta-1)，能够知道其右侧有多少元素小于它
然后在树状数组中删除一个nums[i]+delta-1元素即可
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
    const int delta=10010;
    vector<int> countSmaller(vector<int>& nums) {
        Fenwick<int> fen(delta*2);
        for(auto c:nums) fen.add(c+delta,1);
        vector<int> ans;
        for(auto c:nums){
            ans.push_back(fen.query(c+delta-1));
            fen.add(c+delta,-1);
        }
        return ans;
    }
};
