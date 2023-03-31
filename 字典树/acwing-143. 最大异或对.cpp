/*
01-Trie模板题
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=100010;
int tr[31*N][2],idx;
int a[N];

void insert(int u){
	int p=0;
	for(int i=30;~i;i--){
		int j=(u>>i)&1;
		if(!tr[p][j]) tr[p][j]=++idx;
		p=tr[p][j];
	}
}

int query(int u){
	int p=0,res=0;
	for(int i=30;~i;i--){
		int j=(u>>i)&1;
		if(tr[p][!j]){
			p=tr[p][!j];
			res|=(1<<i);
		}
		else p=tr[p][j];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		insert(a[i]);
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,query(a[i]));
	}
	cout<<ans;
  	return 0;
}
