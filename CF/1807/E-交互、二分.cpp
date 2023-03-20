/*
交互模板+二分模板
按序求所有石子堆数量的前缀和
每次询问前一半区间的石子重量和
如果等于石子数量和，则下一次询问右子区间；否则，下一次询问左子区间

注意要加上⭐fflush(stdout);⭐
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
	fflush(stdout);
	int n;
	cin>>n;
	VI g(n+1);
	rep(i,1,n+1){
		cin>>g[i];
		g[i]+=g[i-1];
	}
	int l=1,r=n;
	while(l<r){
		int m=(l+r)>>1;
		cout<<'?'<<" "<<m-l+1<<" ";
		rep(i,l,m+1) cout<<i<<" ";
		cout<<endl;
		int c;
		cin>>c;
		if(c==g[m]-g[l-1]) l=m+1;
		else r=m;
	}
	cout<<'!'<<" "<<r<<endl;
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
