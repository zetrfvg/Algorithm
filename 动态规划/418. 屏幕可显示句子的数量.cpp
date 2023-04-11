/*
预处理dp
状态定义：
dp[i]：某行从第i个单词开始铺，能够显示多少个句子
next[i]：某行从第i个单词开始铺，最终在哪个单词结束
*/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n=sentence.size();
        vector<int> dp(n),next(n);
        for(int i=0;i<n;i++){
            int len=0,cnt=0,j=i;
            while(len+sentence[j].size()<=cols){
                len+=sentence[j].size()+1;
                if(++j==n){
                    cnt++,j=0;
                }
            }
            dp[i]=cnt,next[i]=j;
        }
        int ans=0;
        for(int i=0,cur=0;i<rows;i++){
            ans+=dp[cur];
            cur=next[cur];
        }
        return ans;
    }
};
