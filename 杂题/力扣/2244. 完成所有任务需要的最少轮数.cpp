/*
若某种类型的任务只有一种则无解
其余部分贪心讨论即可
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> g;
        for(auto c:tasks) g[c]++;
        int ans=0;
        for(auto &[_,c]:g){
            if(c==1) return -1;
            if(c%3==1) c-=4,ans+=2;
            if(c%3==2) c-=2,ans++;
            ans+=c/3;
        }
        return ans;
    }
};
