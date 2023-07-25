/*
按题意模拟拆分即可
*/
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        int n=words.size();
        for(auto t:words){
            t+=separator;
            string u;
            for(auto c:t){
                if(c==separator){
                    if(u.size()) ans.push_back(u);
                    u.clear();
                }else u+=c;
            }
        }
        return ans;
    }
};
