#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int w,h,n,c;
	cin>>w>>h>>n;
	char op;
	multiset<pair<int,int>> sw,sh;
	multiset<int> lw,lh;
	sw.insert({w,0}),sh.insert({h,0});
	lw.insert(w),lh.insert(h);
	while(n--){
		cin>>op>>c;
		if(op=='V'){
			swap(sw,sh);
			swap(lw,lh);
		}
		auto p=sh.lower_bound({c,0});
		lh.erase(lh.find(p->first-p->second));
		lh.insert(p->first-c),lh.insert(c-p->second);
		sh.insert({p->first,c}),sh.insert({c,p->second});
		sh.erase(p);
		if(op=='V'){
			swap(sw,sh);
			swap(lw,lh);
		}
		cout<<1LL*(*lw.rbegin())*(*lh.rbegin())<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
