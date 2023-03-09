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
struct Fenwick{
	int n;
	vector<T> tr;
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

void solve(){
	int n;
	cin>>n;
	vector<VI> g(n);
	VI f,ans(n);
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		g[i]={x,y,i};
		f.pb(x);
		f.pb(y);
	}
	sort(all(f));
	f.resize(unique(all(f))-f.begin());
	auto get=[&](int x){
		return lower_bound(all(f),x)-f.begin()+1;
	};
	sort(all(g),greater<>());
	Fenwick<int> fen(SZ(f));
	rep(i,0,n){
		ans[g[i][2]]=fen.query(get(g[i][1]));
		fen.add(get(g[i][1]),1);
	}
	rep(i,0,n){
		cout<<ans[i]<<'\n';
	}
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
