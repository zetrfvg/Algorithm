/*
a信任b视为a向b连了一条有向边
入度为n-1，出度为0的人必为法官
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> din(n),dout(n);
        for(auto &p:trust){
            dout[p[0]-1]++,din[p[1]-1]++;
        }
        for(int i=0;i<n;i++){
            if(din[i]==n-1&&!dout[i]){
                return i+1;
            }
        }
        return -1;
    }
};
