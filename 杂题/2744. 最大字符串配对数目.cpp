/*
模拟即可，用哈希表记录之前是否出现过该字符的反转
*/
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> st;
        int ans=0;
        for(auto &s:words){
            auto t=s;
            reverse(t.begin(),t.end());
            if(st.count(t)){
                ans++;
                st.erase(t);
            }else{
                st.insert(s);
            }
        }
        return ans;
    }
};
