/*
讲数位排列后，错位组合即可
*/
class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        int x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(i&1){
                x=x*10+s[i]-'0';
            }else{
                y=y*10+s[i]-'0';
            }
        }
        return x+y;
    }
};
