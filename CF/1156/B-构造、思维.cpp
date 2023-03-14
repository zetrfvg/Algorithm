/*
按字符的奇偶性分为a,b两组，奇偶性相同的字符一定可以相邻放置
考虑如下贪心构造：
对a、b进行排序
将a、b拼接起来，a+b或者b+a有任意一个符合要求即可
否则无解
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
	string s;
	cin>>s;
	string a,b;
	rep(i,0,SZ(s)){
		if((s[i]-'a')&1) a+=s[i];
		else b+=s[i];
	}
	sort(all(a));
	sort(all(b));
	if(abs(a.front()-b.back())!=1) cout<<b+a<<'\n';
	else if(abs(b.front()-a.back())!=1) cout<<a+b<<'\n';
	else cout<<"No answer"<<'\n';
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
