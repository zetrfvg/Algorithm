#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	int l=0,r=n-1;
	int last=0,ans=0;
	string s;
	while(l<=r){
		if(a[l]>last&&a[r]>last){
			if(a[l]==a[r]){
				int curL=0,cntL=0,ll=l;
				while(ll<=r&&a[ll]>curL){
					curL=a[ll];
					ll++,cntL++;
				}
				int curR=0,cntR=0,rr=r;
				while(l<=rr&&a[rr]>curR){
					curR=a[rr];
					rr--,cntR++;
				}
				if(cntL>cntR){
					ans+=cntL;
					s+=string(cntL,'L');
				}else{
					ans+=cntR;
					s+=string(cntR,'R');
				}
				break;
			}else if(a[l]<a[r]){
				last=a[l];
				l++,ans++;
				s+='L';
			}else{
				last=a[r];
				r--,ans++;
				s+='R';
			}
		}else if(a[l]>last){
			last=a[l];
			l++,ans++;
			s+='L';
		}else if(a[r]>last){
			last=a[r];
			r--,ans++;
			s+='R';
		}else{
			break;
		}
	}
	cout<<ans<<'\n'<<s<<'\n';
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
