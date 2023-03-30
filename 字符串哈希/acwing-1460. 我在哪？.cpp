/*
二分+字符串哈希+哈希表
时间复杂度：O(nlogn)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
const ll base=13337;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<ll> fac(n+1),hash(n+1);
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*base%mod;
	}
	for(int i=1;i<=n;i++){
		hash[i]=1LL*(hash[i-1]*base+s[i-1]-'a')%mod;
	}
	int l=1,r=n;
	while(l<r){
		int m=(l+r)>>1;
		bool ok=1;
		unordered_set<ll> st;
		for(int s=1,t=s+m-1;t<=n;s++,t++){
			ll h=(hash[t]-(hash[s-1]*fac[m]%mod)+mod)%mod;
			if(st.count(h)){
				ok=0;
				break;
			}else st.insert(h);
		}
		if(ok) r=m;
		else l=m+1;
	}
	cout<<l;
  	return 0;
}
