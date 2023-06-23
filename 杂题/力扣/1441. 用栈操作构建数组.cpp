/*
简单模拟
*/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for(int j=0,i=1;j<target.size();i++){
            ans.push_back("Push");
            if(i==target[j]) j++;
            else ans.push_back("Pop");
        }
        return ans;
    }
};
