/*
按题意模拟即可
*/
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int ans=0;
        for(int i=0;i+k<=s.size();i++){
            int val=stoi(s.substr(i,k));
            if(val&&num%val==0) ans++;
        }
        return ans;
    }
};
