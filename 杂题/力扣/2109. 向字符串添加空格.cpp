/*
按题意模拟
*/
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.size(),m=spaces.size();
        string ans;
        for(int i=0,j=0;i<n;i++){
            if(j<m&&i==spaces[j]) ans+=' ',j++;
            ans+=s[i];
        }
        return ans;
    }
};
