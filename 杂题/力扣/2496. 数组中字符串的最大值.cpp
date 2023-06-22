/*
模拟
*/
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=0;
        for(auto s:strs){
            bool ok=1;
            for(auto c:s){
                if(!isdigit(c)){
                    ok=0;
                    break;
                }
            }
            if(ok) ans=max(ans,stoi(s));
            else ans=max(ans,(int)s.size());
        }
        return ans;
    }
};
