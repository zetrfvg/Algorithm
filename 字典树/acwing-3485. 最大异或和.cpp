#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=100010;
int tr[31*N][2],cnt[31*N],idx;
int s[N];

void insert(int u,int k){
	int p=0;
	for(int i=30;~i;i--){
		int j=(u>>i)&1;
		if(!tr[p][j]) tr[p][j]=++idx;
		p=tr[p][j];
		cnt[p]+=k;
	}
}

int query(int u){
	int p=0,res=0;
	for(int i=30;~i;i--){
		int j=(u>>i)&1;
		if(tr[p][!j]&&cnt[tr[p][!j]]){
			p=tr[p][!j];
			res|=(1<<i);
		}
		else p=tr[p][j];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int ans=0;
	insert(0,1);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]^=s[i-1];
		if(i>=m+1) insert(s[i-m-1],-1);
		ans=max(ans,query(s[i]));
		insert(s[i],1);
	}
	cout<<ans;
  	return 0;
}
