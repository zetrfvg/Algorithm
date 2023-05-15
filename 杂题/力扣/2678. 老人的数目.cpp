/*
模拟
*/
class Solution {
public:
    int countSeniors(vector<string>& s) {
        int ans=0;
        for(auto t:s){
            ans+=stoi(t.substr(11,2))>60;
        }
        return ans;
    }
};
