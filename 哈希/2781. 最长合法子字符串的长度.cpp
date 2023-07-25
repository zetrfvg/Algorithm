/*
因为forbidden中所有串长都不超过10，
双指针，考虑枚举所有右端点，然后向左查询长度不超过10的所有子串是否在forbidden中
如果子串不合法，则左指针移动到当前子串左端点的后面一个位置
*/
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> st(forbidden.begin(),forbidden.end());
        int ans=0;
        int n=word.size();
        for(int l=0,r=0;r<n;r++){
            for(int i=r;i>=l&&i>r-10;i--){
                if(st.count(word.substr(i,r-i+1))){
                    l=i+1;
                    break;
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
