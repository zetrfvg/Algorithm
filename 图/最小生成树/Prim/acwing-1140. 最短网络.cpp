#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<vector<int>> e(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>e[i][j];
		}
	}
	vector<int> d=e[0],vis(n);
	vis[0]=1;
	int ans=0;
	for(int i=1;i<n;i++){
		int u=-1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&(u==-1||d[j]<d[u])) u=j;
		}
		ans+=d[u];
		vis[u]=1;
		for(int j=0;j<n;j++){
			if(!vis[j]) d[j]=min(d[j],e[u][j]);
		}
	}
	cout<<ans;
  	return 0;
}
