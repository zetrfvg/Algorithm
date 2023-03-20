/*
贪心+二分
原序列中的元素额外开辟一个set来存储
对原序列排序，从小到大枚举元素a[i]，我们贪心的选取set中一个最小的且大于它的元素
这样我们就找到一个满足条件的元素匹配，然后从set中移除这个元素，同时继续向后枚举
时间复杂度：O(nlogn)

也可以用双指针优化到O(n)
*/
class Solution {
public:
    int maximizeGreatness(vector<int>& a) {
        multiset<int> st;
        for(auto c:a) st.insert(c);
        int ans=0;
        sort(a.begin(),a.end());
        for(auto c:a){
            auto p=st.upper_bound(c);
            if(p==st.end()) break;
            st.erase(p);
            ans++;
        }
        return ans;
    }
};
