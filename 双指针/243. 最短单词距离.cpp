/*
双指针寻找wordsDict中的串，更新答案即可
*/
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int l=-1,r=-1;
        int ans=1e9;
        for(int i=0;i<wordsDict.size();i++){
            if(wordsDict[i]==word1) l=i;
            if(wordsDict[i]==word2) r=i;
            if(l!=-1&&r!=-1) ans=min(ans,abs(r-l));
        }
        return ans;
    }
};
