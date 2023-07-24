/*
栈模拟即可
遇到向右走的机器人入栈处理
遇到向左走的机器人依次与栈内的机器人进行碰撞即可，直到栈空或者向左走的机器人没有健康值
*/
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<vector<int>> e(n,vector<int>(4));
        for(int i=0;i<n;i++){
            e[i][0]=positions[i],e[i][1]=healths[i];
            if(directions[i]=='L') e[i][2]=0;
            else e[i][2]=1;
            e[i][3]=i;
        }
        sort(e.begin(),e.end());
        vector<int> ans(n,-1);
        stack<vector<int>> st;
        for(int i=0;i<n;i++){
            if(e[i][2]==0){
                while(!st.empty()){
                    auto q=st.top();
                    st.pop();
                    if(q[1]<e[i][1]) e[i][1]--;
                    else if(q[1]==e[i][1]){
                        e[i][1]=-1;
                        break;
                    }
                    else{
                        q[1]--;
                        e[i][1]=-1;
                        st.push(q);
                        break;
                    }
                }
                if(e[i][1]>-1&&st.empty()) ans[e[i][3]]=e[i][1];
            }else{
                st.push(e[i]);
            }
        }
        while(!st.empty()){
            auto q=st.top();
            st.pop(); 
            ans[q[3]]=q[1];
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(ans[i]>-1) res.push_back(ans[i]);
        }
        return res;
    }
};
