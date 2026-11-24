#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> L(n+2),R(n+2,n+1);
	stack<int> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[i]<=a[st.top()]) st.pop();
		if(!st.empty()) L[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i;i--){
		while(!st.empty()&&a[i]<=a[st.top()]) st.pop();
		if(!st.empty()) R[i]=st.top();
		st.push(i);	
	}
	vector<int> ans(n+1);
	for(int i=1;i<=n;i++){
		ans[R[i]-L[i]-1]=max(ans[R[i]-L[i]-1],a[i]);
	}
	for(int i=n-1;i;i--){
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<'\n';
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
