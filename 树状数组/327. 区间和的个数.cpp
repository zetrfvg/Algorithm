/*
前缀和+离散化+树状数组
考虑枚举前i个元素的和s[i]，我们需要找到一个区间[l,r]，使s[i]-s[l]>=lower&&s[i]-s[r]<=upper，并且这个区间长度最长
变形之后即在之前枚举过的前缀和中找两个点使s[i]>=s[l]+lower&&s[i]<=upper+s[r]，由此考虑用值域树状数组来维护
因为值域过大，我们把所有可能出现的数进行离散化操作，然后通过二分的方式来找到每个数离散化之后对应的新元素是多少
然后枚举前缀和，先在树状数组上进行查找，累加答案query(s[i]-lower)-query(s[i]-upper-1)，最后把s[i]加入树状数组中即可
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long long> s(n+1),sum;
        for(int i=0;i<n;i++) s[i+1]=s[i]+nums[i];
        for(int i=0;i<=n;i++){
            sum.push_back(s[i]);
            sum.push_back(s[i]-lower);
            sum.push_back(s[i]-upper);
        }
        sort(sum.begin(),sum.end());
        sum.erase(unique(sum.begin(),sum.end()),sum.end());
        auto get=[&](long long x){
            return lower_bound(sum.begin(),sum.end(),x)-sum.begin()+1;
        };
        Fenwick<int> fen(sum.size()+1);
        int ans=0;
        fen.add(get(0),1);
        for(int i=1;i<=n;i++){
            int l=get(s[i]-upper);
            int r=get(s[i]-lower);
            ans+=fen.query(r)-fen.query(l-1);
            fen.add(get(s[i]),1);
        }
        return ans;
    }
};
