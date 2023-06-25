/*
将(nums1[i],nums2[i])都视为一个平面系上的坐标，对于每个询问，我们需要在它右上角的区域找到nums1[i]+nums2[i]最大点
因为到我们只需要考虑左边和询问之间的相互大小关系，而不需要关注它们具体是多少，因此考虑离散化+扫描线+树状数组
离散化：按横坐标为第一关键字，纵坐标为第二关键字，是否为询问为第三关键字，降序排列(同样的坐标，我们优先处理询问而不是坐标)
扫描线：遇到坐标则加入树状数组(这里树状数组维护纵坐标区间中的最大值)，遇到询问则查询树状数组中的最大值
*/
template<typename T>
struct Fenwick{
	int n;
	vector<T> tr;
	Fenwick(){}
	Fenwick(int _n):tr(_n+1),n(_n){
		for(int i=0;i<=n;i++) tr[i]=-1;
	}
	T lowbit(T x){
		return x&-x;
	}
	void add(int u,T x){
		for(int i=u;i<=n;i+=lowbit(i)) tr[i]=max(tr[i],x);
	}
	T query(int u){
		T res=-1;
		for(int i=u;i;i-=lowbit(i)) res=max(res,tr[i]);
		return res;
	}
};
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size(),m=queries.size();
        map<int,int> p;
        for(int i=0;i<n;i++) p[nums1[i]]=1;
        for(int i=0;i<n;i++) p[nums2[i]]=1;
        for(int i=0;i<m;i++) p[queries[i][0]]=1,p[queries[i][1]]=1;
        int idx=p.size(),sz=p.size();
        for(auto &pp:p) pp.second=idx--;
        vector<int> w(n);
        for(int i=0;i<n;i++){
            w[i]=nums1[i]+nums2[i];
        }
        Fenwick<int> fen(sz+1);
        vector<vector<int>> event;
        for(int i=0;i<n;i++){
            event.push_back({p[nums1[i]],p[nums2[i]],-w[i]});
        }
        for(int i=0;i<m;i++){
            event.push_back({p[queries[i][0]],p[queries[i][1]],i});
        }
        sort(event.begin(),event.end());
        vector<int> ans(m);
        for(auto &e:event){
            int x=e[0],y=e[1],v=e[2];
            if(v<0) fen.add(y,-v);
            else ans[v]=fen.query(y);
        }
        return ans;
    }
};
