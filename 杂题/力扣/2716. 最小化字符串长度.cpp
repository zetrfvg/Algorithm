/*
等价于求s中有多少种不同的字符
*/
class Solution {
public:
    int minimizedStringLength(string s) {
        int ans=0;
        for(int i='a';i<='z';i++){
            ans+=count(s.begin(),s.end(),i)>0;
        }
        return ans;
    }
};
