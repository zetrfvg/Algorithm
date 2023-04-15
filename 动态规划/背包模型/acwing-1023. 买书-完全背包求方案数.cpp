#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> a{0,10,20,50,100};
	vector<vector<int>>dp(5,vector<int>(n+1));
	dp[0][0]=1;
	for(int i=1;i<=4;i++){
		dp[i][0]=1;
		for(int j=0;j<=n;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]+=dp[i][j-a[i]];
		}
	}
	cout<<dp[4][n];
  	return 0;
}
