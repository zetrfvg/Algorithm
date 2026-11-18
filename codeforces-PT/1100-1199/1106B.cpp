#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n),c(n);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		q.push({c[i],i});
	}
	ll ans=0;
	while(m--){
		int t,d;
		cin>>t>>d;
		t--;
		ll sum=0;
		if(a[t]){
			if(a[t]<=d){
				sum+=1LL*a[t]*c[t];
				d-=a[t];
				a[t]=0;
			}else{
				sum+=1LL*d*c[t];
				a[t]-=d;
				d=0;
			}
		}
		while(!q.empty()&&d){
			int j=q.top().second;
			if(a[j]>=d){
				sum+=1LL*d*c[j];
				a[j]-=d;
				d=0;
				break;
			}else{
				sum+=1LL*a[j]*c[j];
				d-=a[j];
				a[j]=0;
			}
			if(!a[j]) q.pop();
		}
		cout<<(d?0:sum)<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
