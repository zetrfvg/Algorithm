/*
构造：二分+树状数组
排序：对身高第一维升序，编号第二维降序排序
用树状数组维护位置，对于枚举的people[i]，我们需要找到当前树状数组中第people[i][1]个空位，这样留出前面people[i][1]-1个空位给身高不小于people[i]的人
找到第people[i][1]个空位，可以在树状数组上二分操作来查找
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        Fenwick<int> fen(n);
        for(int i=1;i<=n;i++) fen.add(i,1);
        sort(people.begin(),people.end(),[](const auto &a,const auto &b){
            return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        });
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            int rk=people[i][1]+1;
            int l=1,r=n;
            while(l<r){
                int m=(l+r)>>1;
                if(fen.query(m)<rk) l=m+1;
                else r=m;
            }
            fen.add(l,-1);
            ans[r-1]=people[i];
        }
        return ans;
    }
};
