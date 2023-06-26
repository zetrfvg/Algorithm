/*
按题意模拟
*/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last=0;
        int ans=0;
        for(auto &s:bank){
            int cnt=count(s.begin(),s.end(),'1');
            if(!cnt) continue;
            ans+=last*cnt;
            last=cnt;
        }
        return ans;
    }
};
