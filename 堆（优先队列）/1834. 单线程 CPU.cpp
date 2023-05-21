/*
堆模拟
*/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        vector<int> ans;
        int i=0;
        long long last=0;
        while(!q.empty()||i<n){
            if(q.empty()){
                last=tasks[i][0];
            }else{
                last+=1LL*q.top().first;
                ans.push_back(q.top().second);
                q.pop();
            }
            while(i<n&&tasks[i][0]<=last){
                q.push({tasks[i][1],tasks[i][2]});
                i++;
            }
        }
        return ans;
    }
};
