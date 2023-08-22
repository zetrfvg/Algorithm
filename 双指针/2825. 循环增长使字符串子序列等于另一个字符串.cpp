/*
双指针枚举字符，基于贪心，如果str1对应的str2字符能变则变
*/
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        for(int i=0,j=0;i<n;i++){
            int x=str1[i]-'a',y=str2[j]-'a';
            if(x==y||((x+1)%26)==y) j++;
            if(j==m) return true;
        }
        return false;
    }
};
