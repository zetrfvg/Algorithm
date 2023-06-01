/*
双指针模拟
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        vector<int> sc(128),tc(128);
        for(auto c:t) tc[c]++;
        auto check=[&](){
            for(int i=0;i<128;i++){
                if(sc[i]<tc[i]) return false;
            }
            return true;
        };
        int mn=1e9,pos;
        for(int l=0,r=0;r<n;r++){
            sc[s[r]]++;
            while(check()){
                if(r-l+1<mn){
                    mn=r-l+1;
                    pos=l;
                }
                sc[s[l++]]--;
            }
        }
        return mn==1e9?"":s.substr(pos,mn);
    }
};
