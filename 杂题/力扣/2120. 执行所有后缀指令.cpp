/*
按题意模拟
*/
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m=s.size();
        vector<int> ans;
        auto get=[&](int u){
            int x=startPos[0],y=startPos[1];
            for(int i=u;i<m;i++){
                if(s[i]=='L') y--;
                else if(s[i]=='R') y++;
                else if(s[i]=='U') x--;
                else x++;
                if(x<0||x>=n||y<0||y>=n) return i-u;
            }
            return m-u;
        };
        for(int i=0;i<m;i++){  
            ans.push_back(get(i));
        }
        return ans;
    }
};
