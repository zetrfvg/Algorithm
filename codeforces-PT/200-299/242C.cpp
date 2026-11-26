#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void solve(){
	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	int n;
	cin>>n;
	set<pair<int,int>> st;
	for(int i=0;i<n;i++){
		int r,x,y;
		cin>>r>>x>>y;
		for(int j=x;j<=y;j++){
			st.insert({r,j});
		}
	}
	queue<tuple<int,int,int>> q;
	q.push({sx,sy,0});
	st.erase({sx,sy});
	while(!q.empty()){
		auto [x,y,d]=q.front();
		q.pop();
		if(x==tx&&y==ty){
			cout<<d;
			return;
		}
		for(int i=0;i<8;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(st.find({xx,yy})!=st.end()){
				q.push({xx,yy,d+1});
				st.erase({xx,yy});
			}
		}
	}
	cout<<-1;
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
