/*
求前缀和依次回答询问
*/
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        auto check=[&](char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        int n=words.size();
        vector<int> s(n+1);
        for(int i=0;i<n;i++){
            s[i+1]=s[i]+(check(words[i].front())&&check(words[i].back()));
        }
        vector<int> ans;
        for(auto q:queries){
            ans.push_back(s[q[1]+1]-s[q[0]]);
        }
        return ans;
    }
};
