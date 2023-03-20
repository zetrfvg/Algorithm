/*
见leetcode-1798. Maximum Number of Consecutive Values You Can Make
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

const int inf=2e5+10;

void solve(){
	int n;
	cin>>n;
	VI g(n);
	rep(i,0,n) cin>>g[i];
	sort(all(g));
	if(g[0]!=1){
		cout<<"NO"<<'\n';
		return;
	}
	int c=1;
	rep(i,1,n){
		if(g[i]>c){
			cout<<"NO"<<'\n';
			return;
		}
		c=min(inf,c+g[i]);
	}
	cout<<"YES"<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
