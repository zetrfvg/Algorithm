/*
按时间戳访问每个点，首先置clock=1
如果首先访问到x点，然后尝试从x出发找其他点，并记出发时间为s
如果找到x之前访问过的点且访问时间不早于s， 则说明构成了一个环，更新最长环的长度clock-s
*/
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int ans=-1,clock=1;
        vector<int> time(n);
        for(int i=0;i<n;i++){
            if(time[i]) continue;
            for(int x=i,s=clock;x>=0;x=edges[x]){
                if(time[x]){
                    if(time[x]>=s){
                        ans=max(ans,clock-time[x]);
                    }
                    break;
                }
                time[x]=clock++;
            }
        }
        return ans;
    }
};
