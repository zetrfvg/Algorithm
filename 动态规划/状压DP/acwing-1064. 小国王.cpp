/*
用二进制表示某一排放置国王的方案，如001001表示在这一排的第1和第4个位置放置了两个国王
首先预处理排除掉所有非法的方案：
1、同一排中不能有相邻的国王放置
2、相邻排中不能有左右距离小于1的国王存在
放在二进制表示中即为：
1、该二进制数不能有两个相邻的1
2、相邻的两个二进制数不能有同样位置的1，也不能有左右距离为1的1

对于筛出来的每个合法状态，把和它能够相邻放置的状态用一个建图的方式存下来

状态定义：
dp[i][j][k]：前i排放置j个国王且第i排的放置状态为k的方案数
转移方程：
dp[i][j][k]=Σdp[i][j-c][k']
其中c为状态k中放置的国王数量，k'为与状态k能够相邻的合法状态
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> state,cnt;
	auto check=[&](int x){
		for(int i=0;i<=30;i++){
			if(((x>>i)&1)&&((x>>(i+1))&1)) return false;
		}
		return true;
	};
	for(int i=0;i<(1<<n);i++){
		if(check(i)){
			state.push_back(i);
			cnt.push_back(__builtin_popcount(i));
		}
	}
	int tot=state.size();
	vector<vector<int>> match(tot);
	for(int i=0;i<tot;i++){
		for(int j=0;j<tot;j++){
			int x=state[i],y=state[j];
			if((x&y)==0&&check(x|y)){
				match[i].push_back(j);
			}
		}
	}
	ll dp[n+1][m+1][tot];
	memset(dp,0,sizeof dp);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int x=0;x<tot;x++){
				for(auto y:match[x]){
					int c=cnt[x];
					if(j>=c) dp[i][j][x]+=dp[i-1][j-c][y];
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<tot;i++){
		ans+=dp[n][m][i];
	}
	cout<<ans;
  	return 0;
}
