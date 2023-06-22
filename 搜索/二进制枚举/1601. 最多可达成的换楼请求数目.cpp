/*
二进制枚举所有请求的组合，对于一组请求，如果每栋楼的出入是相等的，则是合法的组合请求，以此更新答案
*/
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans=0;
        int m=requests.size();
        for(int i=1;i<(1<<m);i++){
            vector<int> cnt(n);
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    cnt[requests[j][0]]--;
                    cnt[requests[j][1]]++;
                }
            }
            if(count(cnt.begin(),cnt.end(),0)==n){
                ans=max(ans,__builtin_popcount(i));
            }
        }
        return ans;
    }
};
