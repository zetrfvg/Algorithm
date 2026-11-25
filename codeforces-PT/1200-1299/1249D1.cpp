#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<tuple<int,int,int>> a(n);
	int top=0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		top=max(top,y);
		a[i]={x,y,i};
	}
	sort(a.begin(),a.end());
	set<pair<int,int>> st;
	int ans=0;
	vector<int> res;
	for(int i=1,j=0;i<=top;i++){
		while(j<n&&get<0>(a[j])==i){
			st.insert({get<1>(a[j]),get<2>(a[j])});
			j++;
		}
		while(st.size()>k){
			res.push_back(st.rbegin()->second+1);
			ans++;
			st.erase(*st.rbegin());
		}
		while(!st.empty()&&st.begin()->first==i){
			st.erase(*st.begin());
		}
	}
	cout<<ans<<'\n';
	for(auto x:res){
		cout<<x<<" ";
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
