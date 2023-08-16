/*
模拟题
*/
class Solution {
public:
    string finalString(string s) {
        string ans;
        for(auto c:s){
            if(c=='i') reverse(ans.begin(),ans.end());
            else ans+=c;
        }
        return ans;
    }
};
