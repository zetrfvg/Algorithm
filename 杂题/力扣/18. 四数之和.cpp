/*
暴力枚举二元组
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        unordered_map<long long,vector<vector<int>>> g;
        set<pair<int,int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=nums[i],y=nums[j];
                if(x>y) swap(x,y);
                if(!st.count({x,y})){
                    g[1LL*nums[i]+nums[j]].push_back({i,j});
                    st.insert({x,y});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(g.count(1LL*target-nums[i]-nums[j])){
                    for(auto &p:g[1LL*target-nums[i]-nums[j]]){
                        bool ok=1;
                        for(auto &c:p){
                            if(c==i||c==j){
                                ok=0;
                                break;
                            }
                        }
                        if(ok){
                            vector<int> t; 
                            for(auto &c:p) t.push_back(nums[c]);
                            t.push_back(nums[i]);
                            t.push_back(nums[j]);
                            sort(t.begin(),t.end());
                            ans.push_back(t);        
                        }                    
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};
