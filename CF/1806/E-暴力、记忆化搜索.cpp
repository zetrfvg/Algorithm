/*
对于未搜索的路径，暴力向上爬树，求答案
同时，用一个哈希表维护已经搜索过的点对，
在接下来某次询问中如果询问的两点都在已经搜索过的点对的子树上则可以加快搜索(虽然这个优化看起来很不怎么样)
用G++17提交会T无法通过，需要用G++20提交
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
	int n,m;
	cin>>n>>m;
	vector<ll> w(n+1);
	VI p(n+1);
	vector<unordered_map<int,ll>> st(n+1);
	rep(i,1,n+1) cin>>w[i];
	rep(i,2,n+1){
		int pa;
		cin>>pa;
		p[i]=pa;
	}
	rep(i,0,m){
		int u,v;
		cin>>u>>v;
		auto get=[&](auto self,int u,int v)->ll{
			if(!u) return 0;
			if(u>v) swap(u,v);
			if(st[u].count(v)) return st[u][v];
			else return st[u][v]=self(self,p[u],p[v])+w[u]*w[v];
		};
		cout<<get(get,u,v)<<'\n';
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
