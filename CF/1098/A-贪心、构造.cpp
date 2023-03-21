/*
基于贪心的思想：
考虑某个偶数层节点x有m个子节点，如果我们给x赋值1，则它所有子节点的赋值也会减少1
那么节点权值和就减少了m-1，为了让权值和最小，我们应当让x的权值尽可能大
而权值又必须非负，我们在所有子节点的权值中找一个最小值赋值给x即可
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

void solve(){
	int n;
	cin>>n;
	vector<VI> g(n+1);
	VI w(n+1);
	rep(i,2,n+1){
		int x;
		cin>>x;
		g[x].pb(i);
	}
	rep(i,1,n+1) cin>>w[i];
	ll ans=0LL;
	bool ok=1;
	auto dfs=[&](auto self,int x,int h,int cur)->void{
		if(h%2==0){
			for(auto y:g[x]){
				w[y]-=cur;
				if(w[y]<0) ok=0;//无解的情况
				if(w[x]==-1) w[x]=w[y];
				else w[x]=min(w[x],w[y]);
			}
			for(auto y:g[x]) w[y]-=w[x];
		}
		ans+=max(0,w[x]);
		for(auto y:g[x]) self(self,y,h+1,cur+w[x]);
	};
	dfs(dfs,1,1,0);
	if(ok){
		cout<<ans<<'\n';
	}else{
		cout<<-1<<'\n';
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
