/*
将边按边权排序，每个询问也按询问的权值排序
依次按询问的权值从小到大回答
对于第i个询问，我们把边权小于等于第i个询问权值的边都加入并查集
在把边加入并查集的同时，考虑它的连接的两个集合各有多少个点
二者的乘积则为加入这条边后，一共增加了多少条路径，这个路径的数量，用变量s来维护
直到把所有边权小于等于第i个询问的边加入到并查集中后，我们就可以回答这个满足这个询问有多少条边了
依次可以回答所有询问

时间复杂度：O(nlogn+qn·α(n))，n为点数，q为询问数，α为并查集的复杂度
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = a;i<n;i++)
#define per(i,a,n) for(int i = n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
typedef vector<int> VI;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) {return mrand()%x;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(int a,int b){return a*b/gcd(a,b);}

template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int n):p(n+1),siz(n+1){
		iota(all(p),0);
		for(int i=0;i<n+1;i++) siz[i]=1;
	}
	T findd(T x){
		return p[x]==x?x:p[x]=findd(p[x]);
	}
	void unionn(T x,T y){
		x=findd(x),y=findd(y);
		if(x==y) return;
		if(siz[x]>siz[y]) swap(x,y);
		p[x]=y;
		siz[y]+=siz[x];
	}
};

void solve(){
	int n,m;
	cin>>n>>m;
	DSU<int> dsu(n);
	vector<VI> e,q(m);
	vector<ll> ans(m);
	rep(i,1,n){
		int x,y,w;
		cin>>x>>y>>w;
		e.pb({w,x,y});
	}
	sort(all(e));
	rep(i,0,m){
		int w;
		cin>>w;
		q[i]={w,i};
	}
	sort(all(q));
	ll s=0;
	for(int i=0,j=0;i<m;i++){
		while(j<n-1&&e[j][0]<=q[i][0]){
			int x=dsu.findd(e[j][1]),y=dsu.findd(e[j][2]);
			s+=1LL*dsu.siz[x]*dsu.siz[y];
			dsu.unionn(x,y);
			j++;
		}
		ans[q[i][1]]=s;
	}
	rep(i,0,m) cout<<ans[i]<<" ";
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
