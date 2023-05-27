/*
分两种操作，一种是只将T改为F；另一种是只将F改成T
以第一种操作为例，双指针枚举所有T的数量不超过k的区间，取最大值即可
第二种操作同理，答案为二者答案的最大值
*/
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size(),cur=0,ans=0;
        for(int l=0,r=0;r<n;r++){
            cur+=answerKey[r]=='T';
            while(cur>k&&l<r){
                cur-=answerKey[l]=='T';
                l++;
            }
            ans=max(ans,r-l+1);
        }
        cur=0;
        for(int l=0,r=0;r<n;r++){
            cur+=answerKey[r]=='F';
            while(cur>k&&l<r){
                cur-=answerKey[l]=='F';
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
