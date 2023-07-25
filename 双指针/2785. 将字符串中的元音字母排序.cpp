/*
找出所有元音字母排序
双指针构造答案即可
*/
class Solution {
public:
    bool check(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string sortVowels(string s) {
        string ans,t;
        for(auto c:s) if(check(c)) t+=c;
        sort(t.begin(),t.end());
        for(int i=0,j=0;i<s.size();i++){
            if(check(s[i])) ans+=t[j++];
            else ans+=s[i];
        }
        return ans;
    }
};
