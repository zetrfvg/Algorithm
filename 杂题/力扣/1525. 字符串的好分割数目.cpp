/*
前后缀分解即可
*/
class Solution {
public:
    int numSplits(string s) {
        int pre=0,suf=0;
        vector<int> c1(26),c2(26);
        for(auto c:s) if(!c2[c-'a']++) suf++;
        int ans=0;
        for(auto c:s){
            if(!c1[c-'a']++) pre++;
            if(!--c2[c-'a']) suf--;
            ans+=pre==suf;
        }
        return ans;
    }
};
