/*
线性筛+埃氏筛
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
vector<int> prim;
int vis[N];

void init(int n){
	memset(vis,0,sizeof vis);
	prim.clear();
	for(int i=2;i<=n;i++){
		if(!vis[i]) prim.push_back(i);
		for(int j=0;prim[j]*i<=n;j++){
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int l,r;
	while(cin>>l>>r){
		init(50000);
		memset(vis,0,sizeof vis);
		for(int i=0;i<prim.size();i++){
			ll p=prim[i];
			for(ll j=max(p*2,(l+p-1)/p*p);j<=r;j+=p){
				vis[j-l]=1;
			}
		}
		vector<int> p;
		for(int i=0;i<=r-l;i++){
			if(!vis[i]&&i+l>=2) p.push_back(i+l);
		}
		if(p.size()<=1){
			printf("There are no adjacent primes.\n");
		}else{
			int mx=0,mn=0;
			for(int i=0;i<p.size()-1;i++){
				int d=p[i+1]-p[i];
				if(d<p[mn+1]-p[mn]) mn=i;
				if(d>p[mx+1]-p[mx]) mx=i;
			}
			printf("%d,%d are closest, %d,%d are most distant.\n",p[mn],p[mn+1],p[mx],p[mx+1]);
		}
	}
  	return 0;
}
