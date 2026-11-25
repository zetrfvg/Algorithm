#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e3+10;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int vis[N][N][4][3];

void solve(){
	int n,m;
	cin>>n>>m;
	vector<string> g(n);
	for(auto &s:g) cin>>s;
	int sx,sy,tx,ty;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='S'){
				sx=i,sy=j;
			}
			if(g[i][j]=='T'){
				tx=i,ty=j;
			}
		}
	}
	queue<tuple<int,int,int,int>> q;
	for(int i=0;i<4;i++){
		vis[sx][sy][i][0]=1;
		q.push({sx,sy,i,0});
	}
	while(!q.empty()){
		auto [x,y,dir,c]=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>=n||yy<0||yy>=m||g[xx][yy]=='*') continue;
			if(dir==i&&!vis[xx][yy][i][c]){
				vis[xx][yy][dir][c]=1;
				q.push({xx,yy,i,c});
			}else if(dir!=i&&c<2&&!vis[xx][yy][i][c+1]){
				vis[xx][yy][i][c+1]=1;
				q.push({xx,yy,i,c+1});
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(vis[tx][ty][i][j]){
				cout<<"YES";
				return;
			}
		}
	}
	cout<<"NO";
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
