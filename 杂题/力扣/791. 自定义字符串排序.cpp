/*
模拟即可
*/
class Solution {
public:
    string customSortString(string order, string s) {
        int f[128];
        memset(f,0,sizeof f);
        for(int i=0;i<order.size();i++) f[order[i]]=i+1;
        sort(s.begin(),s.end(),[&](char a,char b){
            return f[a]<f[b];
        });
        return s;
    }
};
