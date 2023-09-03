/*
从小到大枚举，如果能加入数组则加，判断用哈希表来操作
*/
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans=0;
        unordered_set<int> st;
        for(int i=1,j=0;j<n;i++){
            if(!st.count(target-i)){
                ans+=1LL*i;
                j++;
                st.insert(i);
            }
        }
        return ans;
    }
};
