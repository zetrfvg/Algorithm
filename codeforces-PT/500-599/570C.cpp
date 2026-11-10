#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s="#"+s+"#";
	int sum=0;
	for(int i=2;i<=n;i++){
		if(s[i]=='.'&&s[i-1]=='.') sum++;
	}
	while(m--){
		int p;
		char ch;
		cin>>p>>ch;
		if(s[p]=='.'&&ch!='.'){
			sum-=(s[p-1]=='.')+(s[p+1]=='.');
		}else if(s[p]!='.'&&ch=='.'){
			sum+=(s[p-1]=='.')+(s[p+1]=='.');
		}
		s[p]=ch;
		cout<<sum<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
