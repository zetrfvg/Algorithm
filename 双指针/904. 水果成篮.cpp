/*
双指针，
枚举区间右端点，哈希表来维护区间内水果的种类
如果哈希表大小超过2，则移动左指针，直到哈希表大小为不超过2
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> g;
        int n=fruits.size();
        int ans=0,cur=0;
        for(int l=0,r=0;r<n;r++){
            g[fruits[r]]++;
            while(g.size()>=3){
                if(!--g[fruits[l]]) g.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
