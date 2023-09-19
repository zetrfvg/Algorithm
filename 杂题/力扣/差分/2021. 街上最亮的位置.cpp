/*
因为值域很大，因此用哈希表来维护差分数组，对于light[i]照射范围为[l,r]，在差分数组中令位置(l)++，位置(r+1)--，然后从左到右扫描每个点即可
*/
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int> p;
        for(int i=0;i<lights.size();i++){
            p[lights[i][0]-lights[i][1]]++;
            p[lights[i][0]+lights[i][1]+1]--;
        }
        int cur=0,mx=0,pos;
        for(auto &[a,b]:p){
            cur+=b;
            if(cur>mx) pos=a,mx=cur;
        }
        return pos;
    }
};
