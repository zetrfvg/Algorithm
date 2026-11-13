#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;

void solve(){
	string s;
	cin>>s;
	if(s.find('w')!=string::npos||s.find('m')!=string::npos){
		cout<<0<<'\n';
		return;
	}
	int n=s.size();
	s="#"+s;
	vector<int> dp(n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if((s[i]=='u'&&s[i-1]=='u')||(s[i]=='n'&&s[i-1]=='n')){
			dp[i]=(dp[i-1]+dp[i-2])%mod;
		}else{
			dp[i]=dp[i-1];
		}
	}
	cout<<dp[n]<<'\n';
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
