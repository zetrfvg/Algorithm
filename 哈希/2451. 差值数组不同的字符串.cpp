/*
哈希表记录diff数组出现次数为1的即为答案
*/
class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,int> g;
        for(int i=0;i<words.size();i++){
            vector<int> s;
            for(int j=1;j<words[i].size();j++){
                s.push_back(words[i][j]-words[i][j-1]);
            }
            g[s]++;
        }
        for(int i=0;i<words.size();i++){
            vector<int> s;
            for(int j=1;j<words[i].size();j++){
                s.push_back(words[i][j]-words[i][j-1]);
            }
            if(g[s]==1) return words[i];
        }
        return "";
    }
};
