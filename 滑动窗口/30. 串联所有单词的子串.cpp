/*
暴力算法
一共有m个单词，每个单词长为len
枚举所有长度为m*len的区间
依次判断该区间的子串是否能够由words中的各个单词组成
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size(),m=words.size(),len=words[0].size();
        vector<int> ans,cnt;
        int idx=0;
        unordered_map<string,int> p;
        for(int i=0;i<m;i++){
            if(p.count(words[i])){
                cnt[p[words[i]]]++;
            }
            else{
                cnt.push_back(1);
                p[words[i]]=idx++;
            }
        }
        for(int i=0;i<n;i++){
            if(n-i<len*m) break;
            vector<int> tot(idx);
            int cur=0;
            for(int j=i,c=0;c<m;j+=len,c++){
                string t=s.substr(j,len);
                if(!p.count(t)) break;
                int k=p[t];
                if(++tot[k]>cnt[k]) break;
                cur++;
            }
            if(cur==m) ans.push_back(i);
        }
        return ans;
    }
};
