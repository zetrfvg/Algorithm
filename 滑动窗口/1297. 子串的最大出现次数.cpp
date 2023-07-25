/*
注意到1 <= minSize <= maxSize <= min(26, s.length)
因此可以枚举在合法长度范围内的所有子串，滑动窗口判定加哈希表计数即可
*/
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans=0;
        int n=s.size();
        for(int len=minSize;len<=maxSize;len++){
            int cnt=0;
            vector<int> f(26);
            unordered_map<string,int> sum;
            for(int l=0,r=0;r<n;r++){
                if(!f[s[r]-'a']++) cnt++;
                if(r>=len-1){
                    if(cnt<=maxLetters) ans=max(ans,++sum[s.substr(r-len+1,len)]);
                    if(!--f[s[l++]-'a']) cnt--;
                }
            }
        }
        return ans;
    }
};
