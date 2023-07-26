/*
遍历数组，求一个单调递减的单调栈，栈中最后留存的所有元素即为答案
*/
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        for(int i=0;i<heights.size();i++){
            while(ans.size()&&heights[i]>=heights[ans.back()]) ans.pop_back();
            ans.push_back(i);
        }
        return ans;
    }
};
