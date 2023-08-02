/*
阅读理解，哈希表应用
*/
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> st;
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]==backs[i]) st.insert(backs[i]);
        }
        int ans=1e9;
        for(int i=0;i<fronts.size();i++){
            if(!st.count(fronts[i])) ans=min(ans,fronts[i]);
            if(!st.count(backs[i])) ans=min(ans,backs[i]);
        }
        return ans==1e9?0:ans;
    }
};
