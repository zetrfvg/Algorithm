/*
对于每个points[i]，我们只需要统计在它的右上角区域中包含多少个rectangles[i]的坐标
因为到坐标之间的相互大小关系，而不需要关注它们具体是多少，因此考虑离散化+扫描线+树状数组
离散化：按横坐标为第一关键字，纵坐标为第二关键字，是否为points坐标为第三关键字，降序排列(同样的坐标，我们优先处理矩形而不是坐标)
扫描线：遇到矩形则加入树状数组(这里树状数组维护纵坐标区间中的最大值)，遇到坐标则查询树状数组中的区间和
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
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n=rectangles.size();
        int m=points.size();
        map<int,int> p;
        for(int i=0;i<n;i++){
            p[rectangles[i][0]]=1;
            p[rectangles[i][1]]=1;
        }
        for(int i=0;i<m;i++){
            p[points[i][0]]=1;
            p[points[i][1]]=1;
        }
        int k=p.size(),sz=p.size();
        for(auto &pp:p) pp.second=k--;
        vector<vector<int>> event;
        for(int i=0;i<n;i++){
            event.push_back({p[rectangles[i][0]],p[rectangles[i][1]],-1});
        }
        for(int i=0;i<m;i++){
            event.push_back({p[points[i][0]],p[points[i][1]],i});
        }
        sort(event.begin(),event.end());
        Fenwick<int> fen(sz+1);
        vector<int> ans(m);
        for(int i=0;i<event.size();i++){
            int x=event[i][0],y=event[i][1],j=event[i][2];
            if(j==-1) fen.add(y,1);
            else ans[j]=fen.query(y);
        }
        return ans;
    }
};
