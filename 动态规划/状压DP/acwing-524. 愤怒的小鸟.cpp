/*
思路：枚举这些点最少会被多少条抛物线覆盖
状态定义：
state[i][j]：经过第i个点和第j个点的抛物线能够覆盖到的所有点，如001101表示一共有6个点，表示这条抛物线覆盖了第1、3、4三个点
dp[i]：覆盖点的状态为i时最少需要的抛物线数
转移方程：
dp[i|state[x][j]]=min(dp[i]+1,dp[i|state[x][j]])
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	auto check=[&](double x,double y){
		return fabs(x-y)<=(1e-6);
	};
	while(T--){
		int n,m;
		cin>>n>>m;
		vector<pair<double,double>> p(n);
		vector<vector<int>> state(n,vector<int>(n));
		for(int i=0;i<n;i++){
			cin>>p[i].first>>p[i].second;
		}
		for(int i=0;i<n;i++){
			state[i][i]=(1<<i);
			for(int j=0;j<n;j++){
				double x1=p[i].first,y1=p[i].second;
				double x2=p[j].first,y2=p[j].second;
				if(check(x1,x2)) continue;
				double a=(y1/x1-y2/x2)/(x1-x2);
				double b=y1/x1-a*x1;
				if(a>=0) continue;
				int cur=0;
				for(int k=0;k<n;k++){
					double x=p[k].first,y=p[k].second;
					if(check(a*x*x+b*x,y)){
						cur+=(1<<k);
					}
				}
				state[i][j]=cur;
			}
		}
		vector<int> dp(1<<n,1e9);
		dp[0]=0;
		for(int i=0;i<(1<<n);i++){
			int x=0;
			for(int j=0;j<n;j++){
				if(!((i>>j)&1)){
					x=j;
					break;
				}
			}
			for(int j=0;j<n;j++){
				dp[i|state[x][j]]=min(dp[i]+1,dp[i|state[x][j]]);
			}
		}
		cout<<dp[(1<<n)-1]<<'\n';
	}
  	return 0;
}
