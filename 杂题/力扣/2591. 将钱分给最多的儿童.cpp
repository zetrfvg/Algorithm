/*
无大语题
*/
class Solution {
public:
    int distMoney(int money, int ch) {
        if(money<ch) return -1;
        int ans=0;
        money-=ch;
        if(money%7==3){
            if(money/7==ch-1){
                return ch-2;
            }else{
                return money/7>=ch?ch-1:money/7;
            }
        }else if(money%7==0){
            return money/7>ch?ch-1:money/7;
        }else{
            return money/7>=ch?ch-1:money/7;
        }
    }
};
