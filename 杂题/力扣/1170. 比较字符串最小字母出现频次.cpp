/*
预处理每个words[i]的f值，并求出其后缀和s
对于每个query，我们计算出它的f值，则答案为s[f(query)+1]
*/
class Solution {
public:
    int s[12];
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto calc=[&](string s){
            sort(s.begin(),s.end());
            int p=0;
            while(p<s.size()&&s[p]==s[0]) p++;
            return p;
        };
        memset(s,0,sizeof s);
        int n=words.size();
        for(auto &t:words){
            s[calc(t)]++;
        }
        for(int i=10;~i;i--) s[i]+=s[i+1];
        vector<int> ans;
        for(auto &t:queries){
            ans.push_back(s[calc(t)+1]);
        }
        return ans;
    }
};
