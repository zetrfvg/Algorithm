/*
依次从大到小枚举时间即可
*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> cnt(10);
        for(auto c:arr) cnt[c]++;
        for(int i=1439;~i;i--){
            vector<int> p(10);
            int hours=i/60,minute=i%60;
            if(hours<10){
                p[0]++,p[hours]++;
            }else{
                p[hours/10]++,p[hours%10]++;
            }
            if(minute<10){
                p[0]++,p[minute]++;
            }else{
                p[minute/10]++,p[minute%10]++;
            }
            if(p==cnt) return to_string(hours/10)+to_string(hours%10)+":"+to_string(minute/10)+to_string(minute%10);
        }
        return "";
    }
};
