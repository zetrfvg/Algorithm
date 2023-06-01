/*
枚举一段连续的字符，长度为L，如果它左右两端有空位，则说明可以交换一个字符得到长为L+1的连续字符
然后，我们可以继续向后查找是否有相同的一段连续字符，我们可以替换它们中间的字符，使两段字符合并为一段
要注意的是，合并的字符段长度总共不能超过串中该字符的总数
*/
class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        vector<int> cnt(26);
        for(auto c:text) cnt[c-'a']++;
        int ans=0;
        for(int i=0;i<n;){
            int j=i;
            while(j<n&&text[i]==text[j]) j++;
            int cur=j-i;
            if(cur<cnt[text[i]-'a']&&(i||j<n)) ans=max(ans,cur+1);
            int k=j+1;
            while(k<n&&text[i]==text[k]) k++;
            ans=max(ans,min(cnt[text[i]-'a'],k-i));
            i=j;
        }
        return ans;
    }
};
