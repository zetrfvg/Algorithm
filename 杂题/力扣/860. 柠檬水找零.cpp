/*
找零有10的纸币优先使用10，否则使用5
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0,b=0;
        for(auto &c:bills){
            if(c==5) a++;
            else if(c==10){
                if(!a) return false;
                a--,b++;
            }else{
                if(a&&b) a--,b--;
                else if(a>=3) a-=3;
                else return false;
            }
        }
        return true;
    }
};
