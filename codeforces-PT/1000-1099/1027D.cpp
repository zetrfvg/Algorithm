#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n),c(n),deg(n);
	int idx=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
		deg[a[i]]++;
	}
	queue<int> q;
	vector<int> vis(n);
	for(int i=0;i<n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=1;
		int y=a[x];
		if(!--deg[y]) q.push(y);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			int x=i,res=c[i];
			while(!vis[x]){
				res=min(res,c[x]);
				vis[x]=1;
				x=a[x];
			}
			ans+=res;
		}
	}
	cout<<ans;
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
