#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	unordered_set<int> st;
	string s,t;
	cin>>s>>t;
	auto base=[](string s,int k){
		int res=0;
		for(auto c:s){
			res=res*k+c-'0';
		}
		return res;
	};
	for(int i=0;i<s.size();i++){
		string x=s;
		x[i]^=1;
		if(x.size()>1&&x[0]=='0') continue;
		st.insert(base(x,2));
	}
	for(int i=0;i<t.size();i++){
		for(int j=0;j<3;j++){
			if(t[i]-'0'!=j){
				string x=t;
				x[i]='0'+j;
				if(x.size()>1&&x[0]=='0') continue;
				if(st.count(base(x,3))){
					cout<<base(x,3)<<'\n';
					return 0;
				}
			}
		}
	}
  	return 0;
}
