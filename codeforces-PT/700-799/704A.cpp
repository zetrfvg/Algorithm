#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,q;
	cin>>n>>q;
	int sum=0,idx=0,read=-1;
	vector<queue<int>> app(n);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	while(q--){
		int op,x;
		cin>>op>>x;
		if(op==1){
			x--;
			app[x].push(++idx);
			pq.push({idx,x});
			sum++;
		}else if(op==2){
			x--;
			while(app[x].size()&&app[x].front()<=read){
				app[x].pop();
			}
			sum-=app[x].size();
			while(app[x].size()) app[x].pop();
		}else{
			read=max(read,x);
			while(!pq.empty()&&pq.top().first<=read){
				auto [i,y]=pq.top();
				pq.pop();
				if(app[y].size()&&app[y].front()==i){
					sum--;
					app[y].pop();
				}
			}
		}
		cout<<sum<<'\n';
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
