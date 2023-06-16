/*
状态定义：
dp[i]：技能集合为i所需的最少人数
*/
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people){
        int n=req_skills.size(),m=people.size();
        unordered_map<string,int> p;
        vector<int> skill(m);
        for(int i=0;i<n;i++){
            p[req_skills[i]]=i;//技能赋上新的编号
        }
        for(int i=0;i<m;i++){
            for(auto &s:people[i]){
                skill[i]|=(1<<p[s]);//每个人的技能集合
            }
        }
        vector<int> dp(1<<n,m);
        vector<vector<int>> ans(1<<n);
        dp[0]=0;
        for(int i=1;i<(1<<n);i++){//枚举技能的集合
            for(int j=0;j<m;j++){
                int st=skill[j];
                if((st|i)!=i) continue;//第j个人的拥有的技能并不是i的子集
                for(int k=st;k;k=(k-1)&st){//枚举子集进行状态转移
                    if(dp[i]>dp[i^k]+1){
                        ans[i]=ans[i^k];
                        ans[i].push_back(j);
                        dp[i]=dp[i^k]+1;
                    }
                }
            }
        }
        return ans.back();
    }
};
