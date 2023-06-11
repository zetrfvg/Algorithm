/*
性质：树的重心最多有两个
一个重心：随便删一条边，再连上这条边即可
两个重心：这两个重心一定相连，断开连接这两个重心的边，会生成两个大小相同的树，分别记为a和b
         使重心唯一，只需要从a中取出一个叶子节点，把它连向b即可
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> e[n],sz(n),mx(n);
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			x--,y--;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		function<void(int,int)> dfs=[&](int x,int fa){
			sz[x]=1;
			for(auto y:e[x]){
				if(y==fa) continue;
				dfs(y,x);
				mx[x]=max(mx[x],sz[y]);
				sz[x]+=sz[y];
			}
			mx[x]=max(mx[x],n-sz[x]);
		};
		dfs(0,-1);
		int mn=*min_element(mx.begin(),mx.end());
		vector<int> p;
		for(int i=0;i<n;i++){
			if(mx[i]==mn) p.push_back(i);
		}
		if(p.size()==1){
			cout<<1<<" "<<e[0][0]+1<<'\n';
			cout<<1<<" "<<e[0][0]+1<<'\n';
		}else{
			int son;
			function<void(int,int)> dfs2=[&](int x,int fa){
				if(e[x].size()==1&&e[x][0]==fa){
					son=x;
				}
				for(auto y:e[x]){
					if(y==fa||y==p[1]) continue;
					dfs2(y,x);
				}
			};
			dfs2(p[0],-1);
			cout<<son+1<<" "<<e[son][0]+1<<'\n';
			cout<<son+1<<" "<<p[1]+1<<'\n';
		}
	}
  	return 0;
}
