/*
依次遍历，如果和target[i]不相等则进行一次后缀翻转
*/
class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        for(auto c:target){
            if(c=='1'&&ans%2==0) ans++;
            if(c=='0'&&ans%2==1) ans++;
        }
        return ans;
    }
};
