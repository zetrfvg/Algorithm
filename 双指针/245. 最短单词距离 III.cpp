/*
分情况进行双指针判断即可
*/
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        if(word1!=word2){
            int l=-1,r=-1;
            int ans=1e9;
            for(int i=0;i<wordsDict.size();i++){
                if(wordsDict[i]==word1) l=i;
                if(wordsDict[i]==word2) r=i;
                if(l!=-1&&r!=-1) ans=min(ans,abs(r-l));
            }
            return ans;
        }else{
            int ans=1e9;
            for(int l=-10000000,i=0;i<wordsDict.size();i++){
                if(wordsDict[i]==word1){
                    ans=min(ans,i-l);
                    l=i; 
                }
            }
            return ans;
        }
    }
};
