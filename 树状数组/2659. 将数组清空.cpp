/*
题意转化：
如果当前指针指向最小值，则删除它，否则，指针后移

堆＋树状数组
每次从序列中删除最小值，指针需要从前一个删除的位置移动到当前最小值的位置，我们需要维护这两个位置之间元素的个数，进行查询与修改的操作，由此想到树状数组
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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n=nums.size();
        Fenwick<int> fen(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++){
            q.push({nums[i],i+1});
            fen.add(i+1,1);
        }
        long long ans=0;
        int last=0;
        while(!q.empty()){
            auto [_,i]=q.top();
            q.pop();
            if(i>=last){
                ans+=1LL*fen.query(i)-fen.query(last);
            }else{
                ans+=1LL*fen.query(n)-fen.query(last)+fen.query(i);
            }
            last=i;
            fen.add(i,-1);
        }
        return ans;
    }
};
