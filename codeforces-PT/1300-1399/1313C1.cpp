#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int> st;
	vector<int> L(n+2,0),R(n+2,n+1);
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[i]<a[st.top()]) st.pop();
		if(!st.empty()) L[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i;i--){
		while(!st.empty()&&a[i]<a[st.top()]) st.pop();
		if(!st.empty()) R[i]=st.top();
		st.push(i);
	}
	vector<ll> sumL(n+2),sumR(n+2);
	for(int i=1;i<=n;i++){
		sumL[i]=sumL[L[i]]+1LL*a[i]*(i-L[i]);
	}
	for(int i=n;i;i--){
		sumR[i]=sumR[R[i]]+1LL*a[i]*(R[i]-i);
	}
	ll best=-1;
	int p=1;
	for(int i=1;i<=n;i++){
		ll tot=sumL[i]+sumR[i]-a[i];
		if(tot>best){
			best=tot;
			p=i;
		}
	}
	vector<int> ans(n+2);
	ans[p]=a[p];
	for(int i=p-1;i;i--){
		ans[i]=min(a[i],ans[i+1]);
	}
	for(int i=p+1;i<=n;i++){
		ans[i]=min(a[i],ans[i-1]);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
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
