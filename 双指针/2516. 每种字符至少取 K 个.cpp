/*
从左右两边取走若干个字符，要求取走的a,b,c数量都不少于k
反过来思考，如果s中a,b,c的数量分别为x,y,z，那么问题等价于保留一个区间，其中a,b,c的数量分别不超过x-k,y-k,z-k
转化为了一个双指针枚举最长合法区间的问题
*/
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        vector<int> cnt(3);
        for(auto &c:s) cnt[c-'a']++;
        if(cnt[0]<k||cnt[1]<k||cnt[2]<k) return -1;
        for(auto &c:cnt) c-=k;
        int ans=0;
        for(int l=0,r=0;r<n;r++){
            cnt[s[r]-'a']--;
            while(cnt[s[r]-'a']<0){
                cnt[s[l++]-'a']++;
            }
            ans=max(ans,r-l+1);
        }
        return n-ans;
    }
};
