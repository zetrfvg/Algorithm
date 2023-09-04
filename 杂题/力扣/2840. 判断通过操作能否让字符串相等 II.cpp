/*
将两个字符串的字符按奇偶位分别统计个数，最后判断二者的奇数位各字符数量和偶数位各字符数量是否分别相等即可
*/
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> a(26),b(26),c(26),d(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(i&1){
                a[s1[i]-'a']++;
                c[s2[i]-'a']++;
            }else{
                b[s1[i]-'a']++;
                d[s2[i]-'a']++;
            }
        }
        return a==c&&b==d;
    }
};
