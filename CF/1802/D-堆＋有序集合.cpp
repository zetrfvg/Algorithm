/*
枚举买给朋友A的礼物最大值，用一个大根堆来维护还未枚举到的礼物，B能从中得到的最大值
将枚举过的礼物B能获取的价值存入到一个set中
每次枚举A获得的礼物最大值a
记B能从堆中获取的最大值b1，二分找到set中离a最近的两个元素b2，b3
则每次每枚举用abs(a-b1)、abs(a-b2)、abs(a-b3)中的最小值来更新答案即可
时间复杂度：O(nlogn^2)

此外，也可以用最大值次大值的思路来替代这个set
时间复杂度：O(nlogn)
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
	vector<VI> g(n,VI(2));
	VI b(n),vis(n);
	priority_queue<PII> q;
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		q.push({y,i});
		g[i]={x,i};
		b[i]=y;
	}
	sort(all(g));
	set<int> st;
	ll ans=1e16;
	rep(i,0,n){
		ll x=g[i][0];
		vis[g[i][1]]=1;
		while(!q.empty()&&vis[q.top().se]) q.pop();
		if(!q.empty()&&q.top().fi>x) ans=min(ans,q.top().fi-x);
		else{
			auto p=st.lower_bound(x);
			ll y=1e16,z=1e16,w=1e16;
			if(p!=st.end()) y=*p;
			if(p!=st.begin()) z=*(--p);
			if(!q.empty()) w=q.top().fi;
			ans=min({ans,abs(y-x),abs(x-z),abs(w-x)});
		}
		st.insert(b[g[i][1]]);
	}
	cout<<ans<<'\n';
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
