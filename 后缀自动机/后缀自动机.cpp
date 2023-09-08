/*
ch[x][c]：转移边，x通过字符c转移到的状态
fa[x]：链接边，后缀链接，串str是节点x能表示的最短的子串，fa[x]则指向str的最长后缀的代表的状态
len[x]：节点x能够表示的最长子串的长度
cnt[x]：当前节点中的子串出现的次数
dp[x]：当前节点向后走还能走出多少子串

--整个就是不理解--
性质：
节点子串数量：len[x]-len[fa[x]]

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
vector<int> e[N],dag[N];
ll cnt[N],dp[N];
int tot=1,np=1;
int fa[N],ch[N][26],len[N],deg[N];

void extend(int c){//建立SAM
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

void dfs(int x){//求节点中子串出现的个数
	for(auto y:e[x]){
		dfs(y);
		cnt[x]+=cnt[y];
	}
}

void toposort(){//反向建图跑拓扑
	for(int i=1;i<=tot;i++){
		for(int j=0;j<26;j++){
			if(!ch[i][j]) continue;
			dag[ch[i][j]].push_back(i);
			deg[i]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=tot;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		dp[x]++;
		for(auto y:dag[x]){
			dp[y]+=dp[x];
			if(!--deg[y]) q.push(y);
		}
	}
}

string kth(int k){//求字典序第k小的子串
	string res;
	int p=1;
	while(k){
		for(int i=0;i<26;i++){
			if(!ch[p][i]) continue;
			if(dp[ch[p][i]]<k) k-=dp[ch[p][i]];
			else{
				res+='a'+i;
				p=ch[p][i];
				k--;
				break;
			}
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(auto c:s) extend(c-'a');
	toposort();
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		cout<<kth(k)<<'\n';
	}
	return 0;
}

