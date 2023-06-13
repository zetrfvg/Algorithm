/*
枚举每个质因子p
首先知道p为质因子的数有⌊n/p⌋个，则这里一共贡献了⌊n/p⌋个质因子p
其次，有的数不止一个质因子p，那么考虑p²，这里又贡献了⌊n/p²⌋个因子
从而知道，还有⌊n/p³⌋个质因子
因此这里我们枚举p的幂，累加答案，直到p的幂超过n为止，就能够统计出一共有多少个质因子p
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
vector<int> prim;
int vis[N];

void init(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) prim.push_back(i);
		for(int j=0;prim[j]*i<=n;j++){
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init(N-1);
	int n;
	cin>>n;
	vector<int> cnt;
	for(int i=0;prim[i]<=n;i++){
		int res=0;
		for(ll j=prim[i];j<=n;j*=1LL*prim[i]){
			res+=n/j;
		}
		cnt.push_back(res);
	}
	for(int i=0;i<cnt.size();i++){
		cout<<prim[i]<<" "<<cnt[i]<<'\n';
	}
  	return 0;
}
