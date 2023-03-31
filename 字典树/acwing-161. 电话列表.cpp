/*
字典树模拟插入即可
电话号码s插入过程中，如果开辟了新的节点，说明它一定不是前面已经插入过的电话号码的前缀
如果插入过程中走到了别的串的结尾，说明存在串是s的前缀，不合法
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=100010;
int tr[10*N][10],tail[10*N],idx;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(tr,0,sizeof tr);
		memset(tail,0,sizeof tail);
		idx=0;
		int n;
		cin>>n;
		bool ok;
		string s;
		for(int i=0;i<n;i++){
			int p=0;
			cin>>s;
			ok=0;
			for(auto c:s){
				int j=c-'0';
				if(!tr[p][j]){
					tr[p][j]=++idx;
					ok=1;
				}
				p=tr[p][j];
				if(tail[p]){
					ok=0;
					break;
				}
			}
			if(!ok) break;
			tail[p]=1;
		}
		if(ok){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}
  	return 0;
}
