/*
双指针模拟即可
*/
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int cnt=0;
        for(auto c:pattern) cnt+=(c>='A'&&c<='Z');
        vector<bool> ans;
        for(auto s:queries){
            int l=0,r=0,c=0,n=s.size(),m=pattern.size();
            while(l<n){
                c+=(s[l]>='A'&&s[l]<='Z');
                if(r<m&&s[l]==pattern[r]) r++;
                else if(s[l]>='A'&&s[l]<='Z'){
                    break;
                }
                l++;
            }
            ans.push_back(r==m&&c==cnt);
        }
        return ans;
    }
};
