#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> e(n,vector<int>(n));
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		e[x][y]=e[y][x]=1;
	}
	auto bfs=[&](int rail){
		vector<int> d(n,1e9);
		d[0]=0;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int y=0;y<n;y++){
				if(rail^e[x][y]&&d[x]+1<d[y]){
					d[y]=d[x]+1;
					q.push(y);
				}
			}
		}
		return d[n-1];
	};
	int ans=bfs(e[0][n-1]);
	cout<<(ans==1e9?-1:ans);
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
