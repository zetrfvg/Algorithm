/*
ch[x][c]：转移边，x通过字符c转移到的状态
fa[x]：链接边，后缀链接，串str是节点x能表示的最短的子串，fa[x]则指向str的最长后缀的代表的状态
len[x]：节点x能够表示的最长子串的长度

--整个就是不理解--
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+10;
vector<int> e[N];
ll cnt[N],ans;
int tot=1,np=1;
int fa[N],ch[N][26],len[N];

void extend(int c){
	int p=np;
	np=++tot,len[np]=len[p]+1,cnt[np]=1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if(len[q]==len[p]+1) fa[np]=q;
		else{
			int nq=++tot;
			len[nq]=len[p]+1;
			fa[nq]=fa[q],fa[q]=nq,fa[np]=nq;
			for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			memcpy(ch[nq],ch[q],sizeof ch[q]);
		}
	}
}

void dfs(int x){
	for(auto y:e[x]){
		dfs(y);
		cnt[x]+=cnt[y];
	}
	if(cnt[x]>1) ans=max(ans,cnt[x]*len[x]);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(auto c:s) extend(c-'a');
	for(int i=2;i<=tot;i++) e[fa[i]].push_back(i);
	dfs(1);
	cout<<ans;
	return 0;
}
