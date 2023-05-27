/*
滑动窗口枚举所有长为10的子串，用哈希表来记录子串的数量
找到所有数量大于1的子串即可
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> g;
        int n=s.size();
        for(int i=0;i<=n-10;i++){
            g[s.substr(i,10)]++;
        }
        for(auto &[a,b]:g){
            if(b>1) ans.push_back(a);
        }
        return ans;
    }
};
