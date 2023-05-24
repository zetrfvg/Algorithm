/*
首先对数组排序，双指针两端枚举
如果二者相加不超过limit，则双指针同时向中间移动
否则只移动右指针
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0,l=0,r=people.size()-1;
        sort(people.begin(),people.end());
        while(l<=r){
            ans++;
            if(people[l]+people[r]<=limit) l++;
            r--;
        }
        return ans;
    }
};
