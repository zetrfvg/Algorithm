/*
对于每颗子树，用一个哈希表来维护树上颜色的数量
对于一个节点，合并它各个子树的哈希表时，把更小的哈希表合并到更大的哈希表中
同时维护主要颜色的数量，做答案的更新
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> e[n],col(n),mx(n);
	vector<ll> sum(n);
	map<int,int> p[n];
	for(int i=0;i<n;i++){
		cin>>col[i];
		p[i][col[i]]++;
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		--x,--y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	function<void(int,int)> dfs=[&](int x,int fa){
		mx[x]=1;
		sum[x]=col[x];
		for(auto y:e[x]){
			if(y!=fa){
				dfs(y,x);
				if(p[x].size()<p[y].size()){
					swap(p[x],p[y]);
					mx[x]=mx[y];
					sum[x]=sum[y];
				}
				for(auto &[a,b]:p[y]){
					p[x][a]+=b;
					if(p[x][a]>mx[x]){
						mx[x]=p[x][a];
						sum[x]=a;
					}else if(p[x][a]==mx[x]){
						sum[x]+=1LL*a;
					}
				}
			}
		}
	};
	dfs(0,-1);
	for(int i=0;i<n;i++){
		cout<<sum[i]<<" ";
	}
  	return 0;
}
