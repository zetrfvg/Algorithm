#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]-=i;
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	int ans=1,cur=1;
	for(int i=1;i<a.size();i++){
		// cout<<a[i]<<" ";
		if(a[i]==a[i-1]+1){
			cur++;
			ans=max(ans,cur);
		}else{
			cur=1;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
