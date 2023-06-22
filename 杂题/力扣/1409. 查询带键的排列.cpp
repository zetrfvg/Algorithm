/*
模拟题
*/
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        iota(p.begin(),p.end(),1);
        vector<int> ans;
        for(auto q:queries){
            int pos=0;
            while(p[pos]!=q) pos++;
            for(int i=pos;i;i--) p[i]=p[i-1];
            p[0]=q;
            ans.push_back(pos);
        }
        return ans;
    }
};
