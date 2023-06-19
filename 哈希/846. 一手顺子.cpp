/*
哈希表模拟，每次枚举最小的数，看看是否存在连续的groupsize个元素
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> st(hand.begin(),hand.end());
        while(st.size()){
            for(int i=*st.begin(),j=0;j<groupSize;i++,j++){
                if(!st.count(i)) return false;
                st.erase(st.find(i));
            }
        }
        return true;
    }
};
