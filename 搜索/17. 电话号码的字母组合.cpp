/*
简单搜索
*/
class Solution {
public:
    vector<string> ch{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s;
        int n=digits.size();
        if(!n) return ans;
        function<void(int)> dfs=[&](int i){
            if(i==n){
                ans.push_back(s);
                return;
            }
            for(auto c:ch[digits[i]-'0']){
                s+=c;
                dfs(i+1);
                s.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
