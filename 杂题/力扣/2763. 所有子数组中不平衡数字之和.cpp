/*
枚举元素nums[i]作为右端点的所有子数组
用一个set来记录子数组中的元素，用cnt来表示子数组中的不平衡数字的个数
当子数组的左端点向左扩展时，向集合中添加元素nums[j]
如果set中nums[j]的前驱元素和它的差超过1，此时新扩展的子数组中不平衡数字+1
如果set中nums[j]的后继元素和它的差超过1，此时新扩展的子数组中不平衡数字也要+1
如果set中nums[j]的前驱元素和后继元素的差超过1，说明新的子数组中少了一对不平衡数字
累加答案即可
*/
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            set<int> s;
            s.insert(-1);
            s.insert(1010);
            int cnt=0;
            for(int j=i;j<n;j++){
                if(s.count(nums[j])){
                    ans+=cnt;
                    continue;
                }
                s.insert(nums[j]);
                auto c=s.find(nums[j]);
                auto p=prev(c),q=next(c);
                if(*p!=-1&&*q!=1010){
                    if(*q-*p>1) cnt--;
                    if(*c-*p>1) cnt++;
                    if(*q-*c>1) cnt++;
                }else if(*p!=-1){
                    if(*c-*p>1) cnt++;
                }else if(*q!=1010){
                    if(*q-*c>1) cnt++;
                }
                ans+=cnt;
            }
        }
        return ans;
    }
};
