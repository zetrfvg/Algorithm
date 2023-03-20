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
	int n,m,sx,sy,ex,ey;
	string s;
	cin>>n>>m>>sx>>sy>>ex>>ey>>s;
	unordered_set<ll> st;
	int c=0;
	map<string,int> g;
	g["DL"]=0,g["UL"]=1,g["UR"]=2,g["DR"]=3;
	int dir=g[s];
	while(!st.count(((sx*m+sy)<<2)+dir)){
		st.insert(((sx*m+sy)<<2)+dir);
		if(sx==ex&&sy==ey){
			cout<<c<<'\n';
			return;
		}
		int nx=sx,ny=sy;
		if(dir==0){
			if(sx==n&&sy==1){
				dir=2;
			}else if(sx==n){
				dir=1;
			}else if(sy==1){
				dir=3;
			}else{
				nx=sx+1,ny=sy-1;
			}
		}else if(dir==1){
			if(sx==1&&sy==1){
				dir=3;
			}else if(sx==1){
				dir=0;
			}else if(sy==1){
				dir=2;
			}else{
				nx=sx-1,ny=sy-1;
			}
		}else if(dir==2){
			if(sx==1&&sy==m){
				dir=0;
			}else if(sx==1){
				dir=3;
			}else if(sy==m){
				dir=1;
			}else{
				nx=sx-1,ny=sy+1;
			}
		}else{
			if(sx==n&&sy==m){
				dir=1;
			}else if(sx==n){
				dir=2;
			}else if(sy==m){
				dir=0;
			}else{
				nx=sx+1,ny=sy+1;
			}
		}
		if(nx==sx&&ny==sy){
			c++;
		}else{
			sx=nx,sy=ny;
		}
	}
	cout<<-1<<'\n';
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
