#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void solve(){
	int n,m,s,t,l,r;
	cin>>n>>m;
	cin>>s>>t;
	s--,t--;
	cin>>l>>r;
	vector<string> g(n);
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	deque<pair<int,int>> dq;
	vector<vector<int>> mnR(n,vector<int>(m,1e9));
	mnR[s][t]=0;
	dq.push_back({s,t});
	while(!dq.empty()){
		auto [x,y]=dq.front();
		dq.pop_front();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>=n||yy<0||yy>=m||g[xx][yy]=='*') continue;
			int cost=(i==1?1:0);
			if(mnR[x][y]+cost<mnR[xx][yy]){
				mnR[xx][yy]=mnR[x][y]+cost;
				if(cost){
					dq.push_back({xx,yy});
				}else{
					dq.push_front({xx,yy});
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='*'||mnR[i][j]==1e9) continue;
			if(mnR[i][j]<=r&&mnR[i][j]-j+t<=l&&mnR[i][j]-j+t>=0) ans++; 
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
