/*
堆+哈希表
用一个大根堆来枚举，如果这个元素的标签已经超过uselimit，则跳过，否则累加到答案中
*/
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int,int>> q;
        int n=values.size();
        map<int,int> g;
        int ans=0;
        for(int i=0;i<n;i++){
            q.push({values[i],labels[i]});
        }
        while(!q.empty()&&numWanted){
            auto [w,idx]=q.top();
            q.pop();
            if(g[idx]++>=useLimit) continue;
            ans+=w;
            numWanted--;
        }
        return ans;
    }
};
