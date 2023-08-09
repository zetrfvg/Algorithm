/*
哈希表从小到大枚举数字，进行配对
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> pos,neg;
        int zero=0;
        for(auto c:arr){
            if(c>0) pos[c]++;
            else if(c<0) neg[-c]++;
            else zero++; 
        }
        for(auto [a,b]:pos){
            if(!b) continue;
            if(!pos.count(a*2)||pos[a*2]<b) return false;
            pos[a*2]-=b;
        }
        for(auto [a,b]:neg){
            if(!b) continue;
            if(!neg.count(a*2)||neg[a*2]<b) return false;
            neg[a*2]-=b;
        }
        return zero%2==0;
    }
};
