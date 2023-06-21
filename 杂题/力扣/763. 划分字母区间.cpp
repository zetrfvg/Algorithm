/*
模拟
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> sum(26);
        for(auto c:s) sum[c-'a']++;
        int st=0;
        vector<int> ans;
        for(int l=0,r=0;r<s.size();r++){
            st|=(1<<(s[r]-'a'));
            sum[s[r]-'a']--;
            bool ok=1;
            for(int j=0;j<26;j++){
                if(st&(1<<j)&&sum[j]){
                    ok=0;
                    break;
                }
            }
            if(ok) ans.push_back(r-l+1),l=r+1,st=0;
        }
        return ans;
    }
};
