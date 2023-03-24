/*
双指针+贪心
让source去匹配t的某一段的子序列尽可能的长
*/
class Solution {
public:
    int shortestWay(string source, string target) {
        int n=source.size(),m=target.size();
        int ans=0;
        for(int i=0;i<m;){
            int last=i;
            for(int j=0;j<n;j++){
                if(source[j]==target[i]) i++;
            }
            if(last==i) return -1;
            ans++;
        }
        return ans;
    }
};
