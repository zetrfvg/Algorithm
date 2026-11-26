#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<string> g(n);
	for(auto &s:g) cin>>s;
	vector<vector<vector<int>>> d(n,vector<vector<int>>(m,vector<int>(4,1e9)));
	d[n-1][m-1][2]=0;
	deque<tuple<int,int,int>> q;
	q.push_back({n-1,m-1,2});
	while(!q.empty()){
		auto [x,y,dir]=q.front();
		q.pop_front();
		int xx=x+dx[dir],yy=y+dy[dir];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&d[x][y][dir]<d[xx][yy][dir]){
			d[xx][yy][dir]=d[x][y][dir];
			q.push_front({xx,yy,dir});
		}
		if(g[x][y]=='#'){
			for(int i=0;i<4;i++){
				if(i==dir) continue;
				if(d[x][y][dir]+1>d[x][y][i]) continue;
				d[x][y][i]=d[x][y][dir]+1;
				q.push_back({x,y,i});
			}
		}
	}
	cout<<(d[0][0][2]==1e9?-1:d[0][0][2]);
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
