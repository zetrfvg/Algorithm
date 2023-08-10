/*
简单模拟题
*/
class Solution {
public:
    string alphabetBoardPath(string target) {
        int sx=0,sy=0;
        string ans;
        for(auto c:target){
            int ex=(c-'a')/5,ey=(c-'a')%5;
            if(sx<ex){
                if(sy<ey) ans+=string(ey-sy,'R');
                else if(sy>ey) ans+=string(sy-ey,'L');
                ans+=string(ex-sx,'D');
            }else if(sx>ex){
                ans+=string(sx-ex,'U');
                if(sy<ey) ans+=string(ey-sy,'R');
                else if(sy>ey) ans+=string(sy-ey,'L');
            }else{
                if(sy<ey) ans+=string(ey-sy,'R');
                else if(sy>ey) ans+=string(sy-ey,'L');
            }
            sx=ex,sy=ey;
            ans+="!";
        }
        return ans;
    }
};
