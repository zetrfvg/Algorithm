#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n),d(n,1e9);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}
	d[0]=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x&&d[x]+1<d[x-1]){
			d[x-1]=d[x]+1;
			q.push(x-1);
		}
		if(x<n-1&&d[x]+1<d[x+1]){
			d[x+1]=d[x]+1;
			q.push(x+1);
		}
		if(d[x]+1<d[a[x]]){
			d[a[x]]=d[x]+1;
			q.push(a[x]);
		}
	}
	for(int i=0;i<n;i++) cout<<d[i]<<" ";
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
