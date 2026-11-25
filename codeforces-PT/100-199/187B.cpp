#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll car[65][65][1005];
ll dp[65][65][1005];

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin>>car[x][y][i];
			}
		}
		for(int k=0;k<n;k++){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					car[x][y][i]=min(car[x][y][i],car[x][k][i]+car[k][y][i]);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j][0]=1e16;
			for(int k=0;k<m;k++){
				dp[i][j][0]=min(dp[i][j][0],car[i][j][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j][k]=1e16;
				for(int u=0;u<n;u++){
					dp[i][j][k]=min(dp[i][j][k],dp[i][u][k-1]+dp[u][j][0]);
				}
			}
		}
	}
	while(q--){
		int s,t,k;
		cin>>s>>t>>k;
		s--,t--;
		cout<<dp[s][t][min(k,n-1)]<<'\n';
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
