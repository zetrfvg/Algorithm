/*
类似哈夫曼树的建立过程，每次选取长度最小的两根木棍连接
*/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<>> q(sticks.begin(),sticks.end());
        int ans=0;
        while(q.size()>1){
            int s=q.top();
            q.pop();
            s+=q.top();
            q.pop();
            q.push(s);
            ans+=s;
        }
        return ans;
    }
};
