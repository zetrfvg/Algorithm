#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	vector<int> l(m),r(m);
	for(int i=0,j=0;i<n&&j<m;i++){
		if(s[i]==t[j]){
			l[j]=i;
			j++;
		}
	}
	for(int i=n-1,j=m-1;~i&&~j;i--){
		if(s[i]==t[j]){
			r[j]=i;
			j--;
		}
	}
	int ans=0;
	for(int i=0;i<m-1;i++){
		ans=max(ans,r[i+1]-l[i]);
	}
	cout<<ans;
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
