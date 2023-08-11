/*
逆序模拟
*/
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k=indices.size();
        vector<int> ids(k);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](int i,int j){
            return indices[i]>indices[j];
        });
        for(int i=0;i<k;i++){
            int j=ids[i],sz=sources[j].size();
            if(s.substr(indices[j],sz)==sources[j]){
                s.replace(indices[j],sz,targets[j]);
            }
        }
        return s;
    }
};
