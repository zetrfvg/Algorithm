/*
哈希表模拟设计
*/
class TwoSum {
public:
    unordered_map<int,int> arr;
    TwoSum() {
        
    }
    
    void add(int number) {
        arr[number]++;
    }
    
    bool find(int value) {
        for(auto [a,b]:arr){
            long long t=1LL*value-a;
            if(a==t&&b>1) return true;
            else if(a!=t&&arr.count(t)) return true;
        }
        return false;
    }
};
