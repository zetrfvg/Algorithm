 /*
 求区间交，模拟
 */
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        sort(firstList.begin(),firstList.end());
        sort(secondList.begin(),secondList.end());
        int n=firstList.size(),m=secondList.size();
        vector<vector<int>> ans;
        for(int i=0,j=0;i<n&&j<m;){
            if(secondList[j][0]>firstList[i][1]){
                i++;
                continue;
            }
            if(firstList[i][0]>secondList[j][1]){
                j++;
                continue;
            }
            ans.push_back({max(firstList[i][0],secondList[j][0]),min(firstList[i][1],secondList[j][1])});
            if(firstList[i][1]<secondList[j][1]) i++;
            else if(firstList[i][1]>secondList[j][1]) j++;
            else i++,j++;
        }
        return ans;
    }
};
