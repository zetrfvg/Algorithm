#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> e(n);
	for(int i=0;i<m;i++){
		int x,y;
		string s;
		cin>>x>>y>>s;
		x--,y--;
		if(s=="imposter"){
			e[x].push_back({y,1});
			e[y].push_back({x,1});
		}else{
			e[x].push_back({y,0});
			e[y].push_back({x,0});
		}
	}
	vector<int> col(n,-1);
	int ans=0;
	bool ok=true;
	for(int i=0;i<n;i++){
		if(col[i]==-1){
			queue<int> q;
			q.push(i);
			col[i]=0;
			int c0=1,c1=0;
			while(!q.empty()&&ok){
				int x=q.front();
				q.pop();
				for(auto [y,w]:e[x]){
					int exp=col[x]^w;
					if(col[y]==-1){
						col[y]=exp;
						exp==0?c0++:c1++;
						q.push(y);
					}else if(col[y]!=exp){
						ok=false;
					}
				}
			}
			ans+=max(c0,c1);
		}
		if(!ok) break;
	}
	cout<<(ok?ans:-1)<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
