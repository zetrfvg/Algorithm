/*
简单模拟
*/
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        for(int i=1;;i++){
            if(memory1>=memory2){
                if(memory1<i) return {i,memory1,memory2};
                memory1-=i;
            }else{
                if(memory2<i) return {i,memory1,memory2};
                memory2-=i;
            }
        }
        return {};
    }
};
